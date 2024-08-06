#include "visual05.h"

//--------------------------------------------------------------
visual05::visual05() {
    
    //Load text image
    textImage.load("05/text.png");
    
    //Load palette
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
    
    if (colors.empty()) return;
    
    ofSetColor(colors.back());
    ofDrawRectangle(frame_);
    
    for (int i = 0; i < 100; i++) {
        float ratio = ofMap(i, 0, 100, 1, 0);
        
        float noise = ofNoise(i / engine + time_, time_ / speed);
        
        int colorIndex = ofMap(noise, .1, .9, 0, (int)colors.size());
        colorIndex = ofClamp(colorIndex, 0, (int)colors.size() - 1);
        
        ofSetColor(colors[colorIndex]);
        ofDrawRectangle(frame_.position, frame_.width * ratio, frame_.height * ratio);
    }
    
    ofSetColor(255);
    textImage.draw(frame_);
}
