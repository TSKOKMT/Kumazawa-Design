#pragma once

#include "ofMain.h"

#include "ofxSvg.h"

class visual04 {

public:
    visual04();
    
    void draw(ofRectangle frame_, float time_);
    
private:
    ofImage textImage;
    
    vector<ofPath> pathes;
};
