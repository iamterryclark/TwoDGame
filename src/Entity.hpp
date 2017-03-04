//
//  Entity.hpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include "ofMain.h"

//Reference: From lecture slides on OOP_L2 Constructors & Inheritance and also Marcos game structure code from the shooter example

class Entity {
public:
    //Capturing pos and size from both enemy and player dervied classes
    //Setting health of all entities to 100 at beginning;
    Entity(ofVec2f _pos, int _size, float _health = 100);
   
    //Virtual Functions
    /*Set virtual function to 0 as abstract class doesn't actually do anything such as
      display or fire, so this needs to be virtual so that dererived classes can then redefine
     the function for themselves. */
    virtual void showHealth() = 0; //Display the health of the entities
    virtual void display() = 0;
    virtual void fire() = 0;
    
    //Member Function with Return Values
    int getHealth(); //returns the current health of all entities
    ofVec2f getPos(); //Return current position of all entities
    bool hasCollided();//Collision detection reference http://www.???.com
    bool isDead(); //Check to see if the enetities have died
    
    //Variables
    ofVec2f pos;
    int size;
    int health;
};

#endif /* Entity_hpp */
