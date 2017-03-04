//
//  Enemy.cpp
//  2dGame_PAP
//
//  Created by Terry Clark on 27/02/2017.
//
//

#include "Enemy.hpp"

Enemy::Enemy(ofVec2f _pos, int _size, int _health, ofVec2f _vel, ofVec2f _acc)
: Entity(_pos, _size, _health),  vel(_vel), acc(_acc)
{
    //cout << "Enemy (Child) Init" << endl;
}

void Enemy::display() {
    ofSetColor(ofColor::hotPink);

    float theta = heading(vel) + PI/2;
    
    ofPushMatrix();
    
    //Translate needs to happen before rotate to this is why I need to do this outside of the draw rect function
    ofTranslate(pos);
    ofRotate(theta);
    ofDrawRectangle(0, 0, size, size);
    ofPopMatrix();
}

void Enemy::showHealth(){
    ofMap(getHealth(), 0, 100, 0, 10);
    ofSetColor(ofColor::seaGreen);
    ofFill();
    ofDrawRectangle(pos.x, pos.y - size, health, 10);]
}


void Enemy::update() {
    vel += acc;
    vel.limit(maxspeed);
    pos += vel;
    acc *= 0;
    
}

void Enemy::seek(ofVec2f _target){
    ofVec2f desiredPos = _target - pos;
    float d = sqrt( pow(desiredPos.x, 2) + pow(desiredPos.y, 2) );
    desiredPos.normalize();
    
    if(d < 100) {
        float m = ofMap(d, 0, 100, 0 ,maxspeed);
        desiredPos *= m;
    } else {
        desiredPos *= maxspeed;
    }
    
    ofVec2f steer = desiredPos - vel;
    applyForce(steer);
}

float Enemy::heading(ofVec2f _vector){
    /*
     Reference to calculate angle of rotation of 2d Vector:
     http://math.stackexchange.com/questions/703487/how-can-i-get-a-rotation-angle-from-a-2d-vector
     */
    
    return acos( _vector.x / sqrt( pow( _vector.x, 2) + pow(_vector.y, 2) ));
}

void Enemy::applyForce(ofVec2f force){
    acc += force;
    
}

//Called from Parent Class
void Enemy::fire() {
    
}
