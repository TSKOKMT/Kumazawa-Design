#pragma once

#include "ofMain.h"

#include "ofxSvg.h"

class visual03 {

public:
    visual03();
    
    void draw(ofRectangle frame_, float time_);
    
private:
    ofImage textImage;
    
    vector<ofPath> pathes;
};
