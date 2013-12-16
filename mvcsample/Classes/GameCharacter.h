//
//  GameCharacter.h
//  Masato
//
//  Created by Saket Sinha on 3/05/13.
//
//

#ifndef __mvcsample__GameCharacter__
#define __mvcsample__GameCharacter__
#include "cocos2d.h"
#include "GameObject.h"
#include <iostream>



using namespace cocos2d;
using namespace std;


class GameCharacter : public GameObject
{
public:
    
    CC_SYNTHESIZE(int, _characterHealth, characterHealth);
    CC_SYNTHESIZE(CharacterStates, _characterState, characterState);
    
    GameCharacter();
    virtual ~GameCharacter();
    virtual bool init();
    
    void checkAndClampSpritePosition();
    int getWeaponDamage();
 
};
#endif /* defined(__Masato__GameCharacter__) */