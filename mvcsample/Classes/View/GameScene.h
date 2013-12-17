//
//  GameScene.h
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#ifndef __mvcsample__GameScene__
#define __mvcsample__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "bg.h"
#include "GamePlayLayer.h"

using namespace cocos2d;

class GameScene:public CCLayer {
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(GameScene);
    
};

#endif /* defined(__mvcsample__GameScene__) */
