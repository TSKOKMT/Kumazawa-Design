#pragma once

#include "ofMain.h"

class visual05 {

public:
    visual05();
    
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<float> engine = 50;
    ofParameter<float> speed = 2;
    
private:
    ofImage textImage;
    
    vector<ofColor> colors;
};
