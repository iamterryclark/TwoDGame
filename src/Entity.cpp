//
//  Entity.cpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#include "Entity.hpp"

Entity::Entity(ofVec2f _pos, int _size, float _health)
: pos(_pos), size(_size), health(_health)
{
    //cout << "Entity (Parent) init" << endl;
}

int Entity::getHealth(){
    return health;
}

ofVec2f Entity::getPos(){
    return pos;
}

bool Entity::hasCollided(){
    
    return false;
}

bool Entity::isDead(){
    if (health <= 0){
        return true;
    } else {
        return false;
    }
}
