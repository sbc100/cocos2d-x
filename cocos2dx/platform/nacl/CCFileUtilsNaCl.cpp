/*
 * based on CCFileUtilsLinux.cpp
 */
#include "CCFileUtilsNaCl.h"

#include <sys/stat.h>

using namespace std;

NS_CC_BEGIN

CCFileUtils* CCFileUtils::sharedFileUtils()
{
    if (s_sharedFileUtils == NULL)
    {
        s_sharedFileUtils = new CCFileUtilsNaCl();
        s_sharedFileUtils->init();
    }
    return s_sharedFileUtils;
}

std::string CCFileUtilsNaCl::getWritablePath()
{
    //return current resource path
    return "";
}

bool CCFileUtilsNaCl::isFileExist(const std::string& strFilePath)
{
    std::string strPath = strFilePath;
    if (!isAbsolutePath(strPath))
    { // Not absolute path, add the default root path at the beginning.
        strPath.insert(0, m_strDefaultResRootPath);
    }

    struct stat sts;
    return (stat(strPath.c_str(), &sts) != -1) ? true : false;
}

NS_CC_END
