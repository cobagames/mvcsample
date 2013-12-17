//
//  bg.h
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#ifndef __mvcsample__bg__
#define __mvcsample__bg__
#include <iostream>
#include "GameLayer.h"

using namespace std;




class bg:public GameLayer {
    
    
public:
    
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    
    // a selector callback-
    void menuCloseCallback(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(bg);
    
};

#endif /* defined(__mvcsample__bg__) */
