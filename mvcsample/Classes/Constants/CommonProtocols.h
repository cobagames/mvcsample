//
//  CommonProtocols.h
//  mvcsample
//
//  Created by Saket Sinha on 3/05/13.
//
//

#ifndef mvcsample_CommonProtocols_h
#define mvcsample_CommonProtocols_h

#include "cocos2d.h"

using namespace cocos2d;


typedef enum {
    kStateSpawning,
    kStateBouncing,
    kStateAttacking,
    kStateTapped,
    kStateDead,
    
} CharacterStates;

typedef enum {
    kObjectTypeNone,
    kObjectTypeBall,
    kObjectTypeCollision,
    
} GameObjectType;

class GameplayLayerDelegate
{
public:
    virtual void touchGround(CCPoint startPosition) = 0;
    
};


#endif