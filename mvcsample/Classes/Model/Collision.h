//
//  Collision.h
//  mvcsample
//
//  Created by Saket Sinha on 16/12/2013.
//
//

#ifndef __mvcsample__Collision__
#define __mvcsample__Collision__

#include "GameObject.h"
#include "CommonProtocols.h"

#include <iostream>
class Collision: public GameObject{
private:
    void initAnimations();
    void removeAndClean(CCNode* node);
    CC_SYNTHESIZE(CCAnimation*, _anim, Anim);
    CC_SYNTHESIZE(CharacterStates, _characterState, characterState);
    
public:
    Collision();
    virtual ~Collision();
    virtual bool init();
    virtual void changeState(CharacterStates newState);
    virtual void updateWithDeltaTime(float deltaTime, CCArray *listOfGameObjects);
    
    CC_SYNTHESIZE(CCPoint, _initialPosition, InitialPosition);
    
    CREATE_FUNC(Collision);
};


#endif /* defined(__mvcsample__Collision__) */
