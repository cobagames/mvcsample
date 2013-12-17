//
//  Ball.cpp
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#include "Ball.h"
#include "GameObject.h"

Ball::Ball(){
    
}

Ball::~Ball(){
}

bool Ball::init(){
	//test 1
    if (GameObject::init()) {
        this->setIsActive(true);
        return true;
    }
    return false;
}

void Ball::removeAndClean(CCNode *node){
    this->changeState(kStateDead);
}

void Ball::bounceMe(CCNode *node){
    this->getDelegate()->touchGround(this->getPosition());
    this->changeState(kStateBouncing);
}

void Ball::changeState(CharacterStates newState){
    this->setcharacterState(newState);
    CCAction *action = NULL;
    if (newState == kStateBouncing) {
        CCJumpTo *jumpTo = CCJumpTo::create(1.5f, this->getInitialPosition(), this->getPositionY() + getScreenSize().height/2, 1.0);
        CCSequence *sequence = CCSequence::create(jumpTo, CCCallFuncN::create(this, callfuncN_selector(Ball::bounceMe)) ,NULL);
        action = sequence;
    }
    else if (newState == kStateTapped){
        CCMoveTo *moveTo = CCMoveTo::create(1.5f, ccp(getScreenSize().width, getScreenSize().height));
        CCScaleTo *scaleTo = CCScaleTo::create(1.5f, 0.5f);
        CCSpawn *spawn = CCSpawn::create(moveTo, scaleTo, NULL);
        CCSequence *sequence = CCSequence::create(spawn, CCCallFuncN::create(this, callfuncN_selector(Ball::removeAndClean)) ,NULL);
        action = sequence;
    }
    else if(newState == kStateDead){
        this->setIsActive(false);
        this->setVisible(false);
        this->removeFromParentAndCleanup(true);
    }
    if (action != NULL) {
        this->runAction(action);
    }
}

void Ball::updateWithDeltaTime(float deltaTime, CCArray *listOfGameObjects){

}