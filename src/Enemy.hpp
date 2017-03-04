//
//  Enemy.hpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

//Autonomous Agents Reference: http://natureofcode.com/book/chapter-6-autonomous-agents/
//Code example: https://github.com/shiffman/The-Nature-of-Code-archive/blob/master/raw/noc_html/processingjs/chapter06/_6_02_Arrive/Vehicle.pde

//I wanted the enemy to make its own decisions in how it moves in the game to give the player a sense of challenge when playing the game

#include "ofMain.h"
#include "Entity.hpp"
#include "Player.hpp"

class Enemy : public Entity {
public:
    Enemy(ofVec2f _pos, int _size, int _health, ofVec2f _vel, ofVec2f _acc);
    void showHealth();//Redefined virtual function
    void display();
    void fire();
    void update();
    void seek(ofVec2f _target);
    void applyForce(ofVec2f _force);
    
    float heading(ofVec2f _vector);
    
    ofVec2f vel;
    ofVec2f acc;
    
    float maxspeed = 2.0;
    float maxforce = 0.2;
};
#endif /* Enemy_hpp */

