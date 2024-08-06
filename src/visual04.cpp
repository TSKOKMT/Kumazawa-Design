#include "visual04.h"

//--------------------------------------------------------------
visual04::visual04() {
    
    textImage.load("04/text.png");
    
    ofxSVG svg;
    svg.load("04/shapes.svg");
    pathes = svg.getPaths();
}

//--------------------------------------------------------------
void visual04::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //DRAW
    
    ofSetColor(195, 13, 35);
    ofDrawRectangle(frame_);
    
    for (int i = 0; i < pathes.size(); i++) {
        if ((int)(time_ * 4) % (int)pathes.size() == i) pathes[i].draw();
    }
    
    ofSetColor(255);
    textImage.draw(frame_);
}
