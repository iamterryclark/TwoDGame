#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    player = new Player(ofVec2f(ofGetWidth()/2, ofGetHeight()-100), 20, 100);
    
    enemy = new Enemy(
                      //Location
                      ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()/2)),
                      //size  //Health  //velocity          //accelleration
                      10,     100,     ofVec2f(0.5,0.5),  ofVec2f(0.5,0.5)
                    );
    
//    for (int i = 0; i < 20; i ++){
//        enemies.push_back(new Enemy(ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()/2)),
//                                            20,
//                                            100));
//    }
    
    gameObjects.push_back(player);
    gameObjects.push_back(enemy);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //This runs the osc recevier in order to obtain messages from my device game controller
    //I use TouchOSC to send the messages from my mobile.
    gameController->update();
    
    
    //By checking the bools in the game controller I can call particluar player functions
    if (gameController->isMoving){
        player->move(gameController->movement);
    }
    
    if (gameController->isFiring){
        player->fire();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    
    //I utilise the for each loop in order to access all gameobjects and call their member functions
    //This is done by creating the point to the base class 'Entity' and the game object vector each points to
    //the enemy or player.
    for (auto gameObject : gameObjects){
        //Referenced from class lecture from week 6 regarding Marco's game code
        //By using the dynamic case to check whether the type of the game object is an Enemy pointer type
        //I can then call the particular update function which resides in this class.
        if (dynamic_cast<Enemy*>(gameObject)){
            Enemy* enemyObject = dynamic_cast<Enemy*>(gameObject);
            enemyObject->seek(player->pos);
            enemyObject->update();
            
        }
        
        gameObject->display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //I am using this to test the controlls but will only use gameController in my final project.
    /*switch(key) {
        case ' ':
            player->fire();
        break;
        case OF_KEY_UP:
            player->move(ofVec2f(1,0));
        break;
    }*/
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
