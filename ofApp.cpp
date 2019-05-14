#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    box2d.init();
    box2d.setGravity(0,10);
    box2d.setFPS(30.0);
    box2d.registerGrabbing();

}

//--------------------------------------------------------------
void ofApp::update(){

    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<circles.size();i++)
    {
        ofFill();
        ofSetHexColor(0xffffff);
        circles[i].get()->draw();
    }
    for(int i=0;i<boxes.size();i++)
    {
        ofFill();
        ofSetHexColor(0xffffff);
        boxes[i].get()->draw();
    }
    
    ofDrawBox(300, 600, 0, 1400, 10, 0);
    cupLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        float r =ofRandom(4,20);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0,0.53,0.1);
        circles.back().get()->setup(box2d.getWorld(),mouseX,mouseY,r);
    }
    
    if(key == 'b'){
        float w =ofRandom(4,20);
        float h =ofRandom(4,20);
        boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        boxes.back().get()->setPhysics(3.0,0.53,0.1);
        boxes.back().get()->setup(box2d.getWorld(),mouseX,mouseY,w,h);
    }
    
    if(key == 'q'){
        cupLine.clear();
        int x = ofRandom(600);
        
        cupLine.addVertex(x, x);
        cupLine.addVertex(x+10, x);
        cupLine.addVertex(x+10, x+190);
        cupLine.addVertex(x+230, x+190);
        cupLine.addVertex(x+230, x);
        cupLine.addVertex(x+240, x);
        cupLine.addVertex(x+240, x+200);
        cupLine.addVertex(x, x+200);
        cupLine.close();
        cup = ofPtr<ofxBox2dPolygon>(new ofxBox2dPolygon);
        cup.get()->addVertexes(cupLine);
        cupLine.draw();
        cup.get()->triangulatePoly(10);
        cup.get()->setPhysics(0.0, 0.5, 0.1);
        cup.get()->create(box2d.getWorld());
    }
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
