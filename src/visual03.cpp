#include "visual03.h"

//--------------------------------------------------------------
visual03::visual03() {
    
    textImage.load("03/text.png");
    
    ofxSVG svg;
    svg.load("03/typo.svg");
    pathes = svg.getPaths();
}

//--------------------------------------------------------------
void visual03::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //DRAW
    
    ofSetColor(0, 255, 255);
    ofDrawRectangle(frame_);
    
    for (int i = 0; i < pathes.size(); i++) {
        if ((int)(time_ * 16) % (int)pathes.size() == i) pathes[i].draw();
    }
    
    ofSetColor(255);
    textImage.draw(frame_);
}
