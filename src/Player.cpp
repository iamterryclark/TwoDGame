//
//  Player.cpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#include "Player.hpp"

Player::Player(ofVec2f _pos, int _size, int _health)
: Entity(_pos, _size, _health)
{
    //cout << "Player (Child) Init" << endl;
}


void Player::display() {
    ofSetColor(ofColor::red);
    ofDrawRectangle(pos, size, size);
}

void Player::showHealth(){
    ofMap(getHealth(), 0, 100, 0, 10);
    ofSetColor(ofColor::seaGreen);
    ofFill();
    ofDrawRectangle(pos.x, pos.y + size, health, 10);
}

//Called from Parent Class
void Player::fire() {

}

void Player::move(ofVec2f _movement) {
    pos += _movement;
    // cout << "movement: " << _movement << endl;
}

