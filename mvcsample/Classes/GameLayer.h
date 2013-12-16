//
//  GameLayer.h
//  mvcsample
//
//  Created by Saket Sinha on 15/06/13.
//
//

#ifndef __mvcsample__GameLayer__
#define __mvcsample__GameLayer__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <iostream>

using namespace cocos2d;
using namespace CocosDenshion;

class GameLayer:public CCLayer {
private:
    CC_SYNTHESIZE(CCSize, _screenSize, ScreenSize);
protected:
    CCDictionary* loadEnvironment(CCString *scene);
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);
};

#endif /* defined(__Masato__GameLayer__) */
