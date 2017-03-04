//
//  GameController.cpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#include "GameController.hpp"


GameController::GameController()
{
    oscReceive.setup(PORT);
    //cout << "GameController Init" << endl;
}

GameController::~GameController(){
    //destroy_gameController();
}

void GameController::update(){
    // check for waiting messages
    while( oscReceive.hasWaitingMessages() ){
        // get the next message
        ofxOscMessage m;
        oscReceive.getNextMessage(m);
        
        if(m.getAddress() == "/fire" && m.getArgAsFloat(0) == 1 ){
            isFiring = true;
            //cout << "I'm Fucking Firing!" << endl;
        } else {
            isFiring = false;
        }
        
        if(m.getAddress() == "/special" && m.getArgAsFloat(0) == 1 ){
            useSpecialAttack = true;
            //cout << "I'm Fucking Special!" << endl;
        } else {
            useSpecialAttack = false;
        }
        
        if(m.getAddress() == "/move" ){
            isMoving = true;
            float moveX = ofMap(m.getArgAsFloat(1), 0, 1, -4.0,4.0);
            float moveY = ofMap(m.getArgAsFloat(0), 0, 1, 4.0,-4.0);

            movement = ofVec2f(moveX, moveY);
            //cout << "I'm Fucking Moving! " <<  movement.x << " " <<  movement.y << endl;
        } else {
            isMoving = false;
        }
        
    }
}

GameController& GameController::get_gameController(){
 
    static GameController *gameController = NULL;
    
    if (gameController == NULL){
        gameController = new GameController();
        cout << "GameController Instance Created" << endl;

    }

    return *gameController;

}

void GameController::destroy_gameController(){
    GameController* gameController = &get_gameController();
    
    if (gameController != NULL) {
        delete gameController;
        cout << "GameController Deleted" << endl;
    }
  
}


