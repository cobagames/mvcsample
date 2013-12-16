//
//  GameScene.cpp
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#include "GameScene.h"

bool GameScene::init(){
    if(cocos2d::CCLayer::init()){
        
    }
    return true;
}

CCScene* GameScene::scene(){
    CCScene *scene = CCScene::create();
    
    
    CCLayer *backGroundLayer = bg::create();
    scene->addChild(backGroundLayer, 0);
    
    CCLayer *gamePlayLayer = GamePlayLayer::create();
    scene->addChild(gamePlayLayer, 5);
    return scene;
}