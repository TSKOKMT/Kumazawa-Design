#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //ofSetWindowShape(ofGetScreenWidth() * (16 / 18.), ofGetScreenWidth() / 2.);
    ofSetWindowShape(1920, 1080);
    ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2.);
    ofBackground(0);
    ofSetCircleResolution(60);
    ofSetLineWidth(4);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle("Kumazawa Design | FPS " + ofToString(round(ofGetFrameRate())));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofRectangle frame = ofGetWindowRect();
    
    previousTime = time;
    time = ofGetElapsedTimef();
    
    if (ofWrap(time, 0, 10) < ofWrap(previousTime, 0, 10)) index = ofWrap(index + 1, 0, 6);

    if (index == 0) myVisual01.draw(frame, time);
    else if (index == 1) myVisual02.draw(frame, time);
    else if (index == 2) myVisual03.draw(frame, time);
    else if (index == 3) myVisual04.draw(frame, time);
    else if (index == 4) myVisual05.draw(frame, time);
    else if (index == 5) myVisual06.draw(frame, time);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RIGHT) index = ofWrap(index + 1, 0, 6);
    if (key == OF_KEY_LEFT) index = ofWrap(index - 1, 0, 6);
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
