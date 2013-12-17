//
//  Collision.cpp
//  mvcsample
//
//  Created by Saket Sinha on 16/12/2013.
//
//

#include "Collision.h"
#include "GameObject.h"

Collision::Collision(){
    
}

Collision::~Collision(){
    CC_SAFE_RELEASE(_anim);
}

bool Collision::init(){
	//test .
    if (GameObject::init()) {
        this->setIsActive(true);
        this->initAnimations();
        return true;
    }
    return false;
}

void Collision::removeAndClean(CCNode *node){
    this->changeState(kStateDead);
}

void Collision::changeState(CharacterStates newState){
    this->setcharacterState(newState);
    CCAction *action = NULL;
    if (newState == kStateTapped){
        CCSequence *sequence = CCSequence::create(CCAnimate::create(getAnim()), CCCallFuncN::create(this, callfuncN_selector(Collision::removeAndClean)) ,NULL);
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

void Collision::updateWithDeltaTime(float deltaTime, CCArray *listOfGameObjects){
    
}

void Collision::initAnimations(){
    CCString* animationName = CCString::create("anim");
    CCString* className = CCString::create("CollisionObject");
    this->setAnim(loadPlistForAnimationWithName(animationName, className));
    getAnim()->retain();
    getAnim()->setRestoreOriginalFrame(false);
    
}