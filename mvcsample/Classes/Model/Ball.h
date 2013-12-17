//
//  Ball.h
//  mvcsample
//
//  Created by Saket Sinha on 15/12/2013.
//
//

#ifndef __mvcsample__Ball__
#define __mvcsample__Ball__


#include "GameObject.h"
#include "CommonProtocols.h"

#include <iostream>
class Ball: public GameObject{
private:
    void initAnimations();
    void removeAndClean(CCNode* node);
    void bounceMe(CCNode* node);
    CC_SYNTHESIZE(CharacterStates, _characterState, characterState);
    
public:
    Ball();//
    virtual ~Ball();
    virtual bool init();
    virtual void changeState(CharacterStates newState);
    virtual void updateWithDeltaTime(float deltaTime, CCArray *listOfGameObjects);
    
    CC_SYNTHESIZE(CCPoint, _initialPosition, InitialPosition);
    CC_SYNTHESIZE(GameplayLayerDelegate*, _delegate, Delegate);
    
    CREATE_FUNC(Ball);
};

#endif /* defined(__mvcsample__Ball__) */
