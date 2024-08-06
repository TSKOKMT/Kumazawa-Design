#pragma once

#include "ofMain.h"

#include "ofxSvg.h"

class visual06 {

public:
    visual06();
    
    void draw(ofRectangle frame_, float time_);
    
    float speed = 120;
    
    void bear(int index_);
    
private:
    float time;
    float previousTime;
    
    ofImage textImage;
    
    vector<ofPath> pathes;
    
    vector<ofPath> bornPathes;
};
