//
//  GameObject.h
//  mvcsample
//
//  Created by Saket Sinha on 3/05/13.
//
//

#ifndef __mvcsample__GameObject__
#define __mvcsample__GameObject__


#include "cocos2d.h"
#include "CommonProtocols.h"
#include "Constants.h"
#include "SimpleAudioEngine.h"
#include <iostream>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

class GameObject : public CCSprite
{
protected:
    CC_SYNTHESIZE(CCSize, _screenSize, ScreenSize);
    CC_SYNTHESIZE(CCDictionary*, _environment, Environment);
    

public:
    CC_SYNTHESIZE(bool, _isActive, IsActive);
    CC_SYNTHESIZE(GameObjectType, _gameObjectType, GameObjectType);
    CC_SYNTHESIZE(CCString*, _className, ClassName);
    
    GameObject();
    virtual ~GameObject();
    
    virtual bool init();

    virtual void changeState(CharacterStates newState) = 0;
    virtual void updateWithDeltaTime(float deltaTime, CCArray* listOfGameObjects) = 0;
    CCAnimation* loadPlistForAnimationWithName(CCString* animationName, CCString* className);
};

#endif /* defined(__Masato__GameObject__) */