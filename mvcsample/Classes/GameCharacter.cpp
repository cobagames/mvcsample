//
//  GameCharacter.cpp
//  Masato
//
//  Created by Saket Sinha on 3/05/13.
//
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(){
    
}

GameCharacter::~GameCharacter(){
    //release();
}

bool GameCharacter::init(){
    if(GameObject::init()){
        
    }
    return true;
}

int GameCharacter::getWeaponDamage(){
    //CCLOG("getWeaponDamage should be overriden");
    return 0;
}

void GameCharacter::checkAndClampSpritePosition(){
    CCPoint currentSpritePosition = getPosition();
    
    //ipad
    if(_screenSize.width == 1024){
        if (currentSpritePosition.x < 30.0f) {
            CCNode::setPosition(30.0f, currentSpritePosition.y);

        } else if (currentSpritePosition.x > 1000.0f) {
            CCNode::setPosition(1000.0f, currentSpritePosition.y);
        }
    }
}