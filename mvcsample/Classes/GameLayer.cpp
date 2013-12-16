//
//  GameLayer.cpp
//  Masato
//
//  Created by Saket Sinha on 15/06/13.
//
//

#include "GameLayer.h"

bool GameLayer::init(){
    if (CCLayer::init()) {
        _screenSize = CCDirector::sharedDirector()->getWinSize();
        return true;
    }
    return false;
}

CCDictionary* GameLayer::loadEnvironment(CCString *scene){
    CCDictionary *plist = CCDictionary::createWithContentsOfFile(scene->getCString());
    CCDictionary *environment = NULL;
    if (this->getScreenSize().height == 640 && this->getScreenSize().width == 1136) {
        environment = (CCDictionary*)plist->objectForKey("iPhone-5");
    }
    else if (this->getScreenSize().height == 640 && this->getScreenSize().width == 960) {
        environment = (CCDictionary*)plist->objectForKey("iPhoneHD");
    }
    else{
        environment = (CCDictionary*)plist->objectForKey("iPhone");
    }
    environment->retain();
    return environment; 
}