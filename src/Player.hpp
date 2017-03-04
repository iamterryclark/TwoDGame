//
//  Player.hpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#ifndef Player_hpp
#define Player_hpp

#include "ofMain.h"
#include "Entity.hpp"
#include "Weapon.hpp"

class Player : public Entity {
public:
    Player(ofVec2f _pos, const int _size, int _health);
    void showHealth(); //Redefined virtual function
    void display();
    void fire();
    void move(ofVec2f _movement);
};
#endif /* Player_hpp */
