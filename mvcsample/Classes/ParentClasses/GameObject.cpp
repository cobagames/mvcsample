//
//  GameObject.cpp
//  Masato
//
//  Created by Saket Sinha on 3/05/13.
//
//

#include "GameObject.h"

GameObject::GameObject()
{
    
}

GameObject::~GameObject()
{
    
}

bool GameObject::init(){
    if(CCSprite::init()){
        _screenSize = CCDirector::sharedDirector()->getWinSize();
        this->setIsActive(true);
        this->setGameObjectType(kObjectTypeNone);
    }
    return true;
}

CCAnimation* GameObject::loadPlistForAnimationWithName(CCString* animationName, CCString* className){
    
    CCAnimation *animationToReturn = CCAnimation::create();
    CCSpriteFrame *frame;
    CCString *frameName;
    
    CCDictionary *plist = CCDictionary::createWithContentsOfFile(CCString::createWithFormat("%s.plist",className->getCString())->getCString());
    CCDictionary *anim = (CCDictionary*)plist->objectForKey(animationName->getCString());
    CCString *fileNamePrefix = (CCString*)anim->objectForKey("fileNamePrefix");
    CCString *delay = (CCString*)anim->objectForKey("delay");
    CCString *animationFrames = (CCString*)anim->objectForKey("animationFrames");
    
    std::vector<int> vect;
    
    std::stringstream ss(animationFrames->getCString());
    int i;
    
    while (ss >> i)
    {
        vect.push_back(i);
         
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (vector<int>::size_type i = 1; i <= vect.size(); ++i)
    {
        frameName = CCString::createWithFormat("%s%i.png",fileNamePrefix->getCString(),i);
        frame= CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName->getCString());
        animationToReturn->addSpriteFrame(frame);
    }
    animationToReturn->setDelayPerUnit(delay->floatValue());
    return animationToReturn;
}
