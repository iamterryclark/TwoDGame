//
//  GameController.hpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 7000

//Singleton References
//Reference: https://www.youtube.com/watch?v=uTG-cSGdcAE
//Reference: https://www.youtube.com/watch?v=zC6dWIr5804

class GameController {
    
    //Singletons need to have the constructor and deconstructor as private to stop other objects from accessing them and creating new ones
private:
    GameController();
    ~GameController();
public:
    
    //Static functions are a way to only allow one copy of the function to be used
    //So we can make multiple objects of game controller but we will only use one instance of it
    //Reference: https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
    static GameController& get_gameController();
    static void destroy_gameController();
    void update();
    
    //External Classes
    ofxOscReceiver oscReceive;
    
    //Variables
    //In order to control the player I am using bools to test the osc messages I can then call this singleton class within the
    //player class to trigger the different functions
    bool isFiring;
    bool useSpecialAttack;
    bool isMoving;
    ofVec2f movement;
};

#endif /* GameController_hpp */
