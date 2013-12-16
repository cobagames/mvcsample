//
//  GamePlayLayer.h
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#ifndef __mvcsample__GamePlayLayer__
#define __mvcsample__GamePlayLayer__

#include <iostream>
#include "CommonProtocols.h"
#include "Constants.h"
#include "GameLayer.h"
#include "GameCharacter.h"
#include "Ball.h"
#include "Collision.h"


class GamePlayLayer: public GameLayer, public GameplayLayerDelegate {
    
    
public:
    
    GamePlayLayer();
    virtual ~GamePlayLayer();
    
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    virtual void createObjectOfType(GameObjectType objectType, int initialHealth, CCPoint spawnLocation, int ZValue);
    virtual void touchGround(CCPoint startPosition);
    
    CREATE_FUNC(GamePlayLayer);
    
private:
    CCPoint _touchBeganPoint;
    
    CC_SYNTHESIZE(CCSize, _screenSize, ScreenSize);
    CC_SYNTHESIZE(CCSpriteBatchNode*, _sceneSpriteBatchNode, SceneSpriteBatchNode);
    CC_SYNTHESIZE(CCDictionary*, _environment, Environment);
    CC_SYNTHESIZE(float, _bounceInterval, BounceInterval);
    CC_SYNTHESIZE(float, _bounceTimer, BounceTimer);
    
    void update(float dt);
    void removeAndClean(CCNode *node);
    virtual void ccTouchesBegan(CCSet* touches, CCEvent* event);
    virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);
    
    
};


#endif /* defined(__mvcsample__GamePlayLayer__) */
