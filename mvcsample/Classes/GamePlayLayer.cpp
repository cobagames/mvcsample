//
//  GamePlayLayer.cpp
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#include "GamePlayLayer.h"

GamePlayLayer::GamePlayLayer(){
    
}

GamePlayLayer::~GamePlayLayer(){
    CC_SAFE_RELEASE(_sceneSpriteBatchNode);
    CC_SAFE_RELEASE(_environment);
}

bool GamePlayLayer::init(){
    
    if(GameLayer::init()){
        
        setBounceInterval(2.0f);
        setBounceTimer(0.0f);
        
        setScreenSize(CCDirector::sharedDirector()->getWinSize());
        setEnvironment(loadEnvironment(CCString::create("SceneAttributes.plist")));
        getEnvironment()->retain();
        CCString *atlas = (CCString*)getEnvironment()->objectForKey("atlas");
        CCString *plistName = CCString::createWithFormat("%s.plist", atlas->getCString());
        CCString *fileName = CCString::createWithFormat("%s.png", atlas->getCString());
        
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plistName->getCString());
        setSceneSpriteBatchNode(CCSpriteBatchNode::create(fileName->getCString()));
        
        
        this->setTouchEnabled(true);
        this->addChild(_sceneSpriteBatchNode, 0);
        this->createObjectOfType(kObjectTypeBall, 5, ccp(getScreenSize().width/2,getScreenSize().height/8.0), kZValue);
        
        this->schedule(schedule_selector(GamePlayLayer::update));
    }
    return true;
}



void GamePlayLayer::update(float dt){
    CCArray *listOfGameObjects = _sceneSpriteBatchNode->getChildren();
    CCObject* obj = NULL;
    
    CCARRAY_FOREACH(listOfGameObjects, obj){
        GameCharacter* character = (GameCharacter*)obj;
        if(character->getIsActive() == true && character != NULL){
            character->updateWithDeltaTime(dt, listOfGameObjects);
        }
    }
    setBounceTimer(getBounceTimer() + dt);
    
    if (getBounceTimer() > getBounceInterval()) {
        
        Ball* ball = (Ball*)_sceneSpriteBatchNode->getChildByTag(kObjectTypeBall);
        if (ball == NULL) {
            return;
        }
        if (rand() % 100 < 50 && ball->getInitialPosition().x < getScreenSize().width) {
            ball->setInitialPosition(ccp(ball->getInitialPosition().x + 200, getScreenSize().height/8.0));
        }
        else if(ball->getInitialPosition().x > 0){
            ball->setInitialPosition(ccp(ball->getInitialPosition().x - 200, getScreenSize().height/8.0));
        }
        setBounceTimer(0.0f);
    }
}


void GamePlayLayer::removeAndClean(CCNode *node){
    node->setVisible(false);
    node->removeFromParentAndCleanup(true);
}

void GamePlayLayer::createObjectOfType(GameObjectType objectType, int initialHealth, CCPoint spawnLocation, int ZValue){
    if(objectType == kObjectTypeBall){
        Ball* ball = Ball::create();
        ball->setDelegate(this);
        ball->initWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ball_1.png"));
        ball->setPosition(spawnLocation);
        ball->setInitialPosition(spawnLocation);
        ball->changeState(kStateBouncing);
        _sceneSpriteBatchNode->addChild(ball, ZValue, kBallTagValue);
    }
    else if (objectType == kObjectTypeCollision){
        Collision *collision = Collision::create();
        collision->initWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("collision_1.png"));
        collision->setPosition(spawnLocation);
        collision->changeState(kStateTapped);
        _sceneSpriteBatchNode->addChild(collision, ZValue, kBallTagValue);
        
    }
    
}

void GamePlayLayer::ccTouchesBegan(CCSet *touches, CCEvent *event){
    CCTouch* touch = (CCTouch*)touches->anyObject();
    _touchBeganPoint = touch->getLocation();
    Ball* ball = (Ball*)_sceneSpriteBatchNode->getChildByTag(kObjectTypeBall);
    if (ball != NULL && ball->boundingBox().containsPoint(touch->getLocation())) {
        ball->stopAllActions();
        ball->changeState(kStateTapped);
        this->createObjectOfType(kObjectTypeBall, 5, ccp(getScreenSize().width/2,getScreenSize().height/8.0), kZValue);
    }
    
}

void GamePlayLayer::ccTouchesEnded(CCSet *touches, CCEvent *event){

    
}

void GamePlayLayer::touchGround(CCPoint startPosition){
    this->createObjectOfType(kObjectTypeCollision, 5, startPosition, kZValue);
}


void GamePlayLayer::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
