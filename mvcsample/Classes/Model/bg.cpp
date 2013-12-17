//
//  bg.cpp
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#include "bg.h"

bool bg::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !GameLayer::init() )
    {
        return false;
    }
    
    //////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(bg::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCDictionary *environment = loadEnvironment(CCString::create("SceneAttributes.plist"));
    CCString *bg = (CCString*)environment->objectForKey("bg");
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite* pSprite = CCSprite::create(CCString::createWithFormat("%s.png", bg->getCString())->getCString());
    
    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}

void bg::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
