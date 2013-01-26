#include "SimpleAudioEngine.h"

namespace CocosDenshion {

SimpleAudioEngine::SimpleAudioEngine() {
}

SimpleAudioEngine::~SimpleAudioEngine() {
}

SimpleAudioEngine* SimpleAudioEngine::sharedEngine() {
    return NULL;
}

void SimpleAudioEngine::end() {
}

void SimpleAudioEngine::playBackgroundMusic(const char* pszFilePath,
        bool bLoop) {
}

void SimpleAudioEngine::stopBackgroundMusic(bool bReleaseData) {
}

void SimpleAudioEngine::pauseBackgroundMusic() {
}

void SimpleAudioEngine::resumeBackgroundMusic() {
}

void SimpleAudioEngine::rewindBackgroundMusic() {
}

bool SimpleAudioEngine::willPlayBackgroundMusic() {
    return false;
}

bool SimpleAudioEngine::isBackgroundMusicPlaying() {
    return false;
}

void SimpleAudioEngine::preloadBackgroundMusic(const char* pszFilePath) {
}

unsigned int SimpleAudioEngine::playEffect(const char* pszFilePath,
        bool bLoop) {
    return 0;
}

void SimpleAudioEngine::stopEffect(unsigned int nSoundId) {
}

void SimpleAudioEngine::preloadEffect(const char* pszFilePath) {
}

void SimpleAudioEngine::unloadEffect(const char* pszFilePath) {
}

void SimpleAudioEngine::pauseEffect(unsigned int uSoundId) {
}

void SimpleAudioEngine::pauseAllEffects() {
}

void SimpleAudioEngine::resumeEffect(unsigned int uSoundId) {
}

void SimpleAudioEngine::resumeAllEffects() {
}

void SimpleAudioEngine::stopAllEffects() {
}

float SimpleAudioEngine::getBackgroundMusicVolume() {
    return 0.0f;
}

void SimpleAudioEngine::setBackgroundMusicVolume(float volume) {
}

float SimpleAudioEngine::getEffectsVolume() {
    return 0.0f;
}

void SimpleAudioEngine::setEffectsVolume(float volume) {
}

/*
const char * _FullPath(const char * szPath) {
}

unsigned int _Hash(const char *key) {
}
*/

} // namespace CocosDenshion
