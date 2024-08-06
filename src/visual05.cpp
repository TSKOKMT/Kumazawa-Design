#include "visual05.h"

//--------------------------------------------------------------
visual05::visual05() {
    
    textImage.load("05/text.png");
    
    ofImage palette;
    palette.load("05/palette.png");
    for (int i = 0; i < palette.getWidth(); i++) {
        colors.push_back(palette.getColor(i, 0));
    }
}

//--------------------------------------------------------------
void visual05::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //DRAW
    
    ofSetColor(colors.back());
    ofDrawRectangle(frame_);
    
    for (int i = 0; i < 100; i++) {
        float ratio = ofMap(i, 0, 100, 1, 0);
        
        float noise = ofNoise(i / engine + time_, time_ / speed);
        
        ofSetColor(colors[ofClamp(ofMap(noise, .1, .9, 0, (int)colors.size()), 0, (int)colors.size() - 1)]);
        //ofSetColor(colors[i % (int)colors.size()]);
        ofDrawRectangle(frame_.position, frame_.width * ratio, frame_.height * ratio);
    }
    
    ofSetColor(255);
    textImage.draw(frame_);
}
