#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetWindowShape(1920, 1080);
    ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2.);
    ofBackground(0);
    ofSetCircleResolution(60);
    ofSetLineWidth(4);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle("Kumazawa Design 05 | FPS " + ofToString(round(ofGetFrameRate())));
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofRectangle frame = ofGetWindowRect();
    
    float time = ofGetElapsedTimef();

    myVisual05.draw(frame, time);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
