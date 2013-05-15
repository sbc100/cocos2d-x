/* Copyright (c) 2012 Scott Lembcke and Howling Moon Software
 * Copyright (c) 2012 cocos2d-x.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "CCPhysicsNode.h"
#include "support/CCPointExtension.h"

#if CC_ENABLE_CHIPMUNK_INTEGRATION
#include "chipmunk.h"
#elif CC_ENABLE_BOX2D_INTEGRATION
#include "Box2D/Box2D.h"
#endif

NS_CC_EXT_BEGIN

CCPhysicsNode::CCPhysicsNode()
: m_bIgnoreBodyRotation(false)
#if CC_ENABLE_CHIPMUNK_INTEGRATION
, m_pCPBody(NULL)
#elif CC_ENABLE_BOX2D_INTEGRATION
, m_pB2Body(NULL)
, m_fPTMRatio(0.0f)
#endif
{}

CCPhysicsNode* CCPhysicsNode::create()
{
    CCPhysicsNode* pRet = new CCPhysicsNode();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }

    return pRet;
}

bool CCPhysicsNode::isIgnoreBodyRotation() const
{
    return m_bIgnoreBodyRotation;
}

void CCPhysicsNode::setIgnoreBodyRotation(bool bIgnoreBodyRotation)
{
    m_bIgnoreBodyRotation = bIgnoreBodyRotation;
}

// Override the setters and getters to always reflect the body's properties.
const CCPoint& CCPhysicsNode::getPosition()
{
    updatePositionFromPhysics();
    return CCNode::getPosition();
}

void CCPhysicsNode::getPosition(float* x, float* y)
{
    updatePositionFromPhysics();
    return CCNode::getPosition(x, y);
}

float CCPhysicsNode::getPositionX()
{
    updatePositionFromPhysics();
    return m_obPosition.x;
}

float CCPhysicsNode::getPositionY()
{
    updatePositionFromPhysics();
    return m_obPosition.y;
}

float CCPhysicsNode::getRotation()
{
    updateRotationFromPhysics();
    return CCNode::getRotation();
}

// returns the transform matrix according the Box2D Body values
CCAffineTransform CCPhysicsNode::nodeToParentTransform()
{
    updatePositionFromPhysics();
    updateRotationFromPhysics();
    return CCNode::nodeToParentTransform();
}

#if CC_ENABLE_CHIPMUNK_INTEGRATION

cpBody* CCPhysicsNode::getCPBody() const
{
    return m_pCPBody;
}

void CCPhysicsNode::setCPBody(cpBody *pBody)
{
    m_pCPBody = pBody;
}

void CCPhysicsNode::updatePositionFromPhysics()
{
    cpVect cpPos = cpBodyGetPos(m_pCPBody);
    m_obPosition = ccp(cpPos.x, cpPos.y);
}

void CCPhysicsNode::updateRotationFromPhysics()
{
    if (!m_bIgnoreBodyRotation)
    {
        CCNode::setRotation(-CC_RADIANS_TO_DEGREES(cpBodyGetAngle(m_pCPBody)));
    }
}

void CCPhysicsNode::setPosition(const CCPoint &pos)
{
    cpVect cpPos = cpv(pos.x, pos.y);
    cpBodySetPos(m_pCPBody, cpPos);
}

void CCPhysicsNode::setRotation(float fRotation)
{
    if (!m_bIgnoreBodyRotation)
    {
        cpBodySetAngle(m_pCPBody, -CC_DEGREES_TO_RADIANS(fRotation));
    }
    else
    {
        CCNode::setRotation(fRotation);
    }
}

#elif CC_ENABLE_BOX2D_INTEGRATION

b2Body* CCPhysicsNode::getB2Body() const
{
    return m_pB2Body;
}

void CCPhysicsNode::setB2Body(b2Body *pBody)
{
    m_pB2Body = pBody;
}

float CCPhysicsNode::getPTMRatio() const
{
    return m_fPTMRatio;
}

void CCPhysicsNode::setPTMRatio(float fRatio)
{
    m_fPTMRatio = fRatio;
}

void CCPhysicsNode::updateRotationFromPhysics()
{
    if (!m_bIgnoreBodyRotation)
    {
        float angle = m_pB2Body->GetAngle();
        CCNode::setRotation(-CC_RADIANS_TO_DEGREES(angle));
    }
}

void CCPhysicsNode::updatePositionFromPhysics()
{
    b2Vec2 pos = m_pB2Body->GetPosition();
    float x = pos.x * m_fPTMRatio;
    float y = pos.y * m_fPTMRatio;
    m_obPosition = ccp(x,y);
    if (m_pParent)
        m_obPosition = m_pParent->convertToNodeSpace(m_obPosition);
}

void CCPhysicsNode::setPosition(const CCPoint &pos)
{
    float angle = m_pB2Body->GetAngle();
    CCPoint world_pos = pos;
    if (m_pParent)
      world_pos = m_pParent->convertToWorldSpace(world_pos);
    m_pB2Body->SetTransform(b2Vec2(world_pos.x / m_fPTMRatio, world_pos.y / m_fPTMRatio), angle);
}

void CCPhysicsNode::setRotation(float fRotation)
{
    if (!m_bIgnoreBodyRotation)
    {
        b2Vec2 p = m_pB2Body->GetPosition();
        float radians = CC_DEGREES_TO_RADIANS(fRotation);
        m_pB2Body->SetTransform(p, radians);
    }
    else
    {
        CCNode::setRotation(fRotation);
    }
}
#endif

NS_CC_EXT_END
