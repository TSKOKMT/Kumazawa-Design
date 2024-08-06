#pragma once

#include "ofMain.h"

#include "ofxSvg.h"

class visual02 {

public:
    visual02();
    
    void draw(ofRectangle frame_, float time_);
    
private:
    ofImage textImage;
    
    vector<ofPolyline> riverLines;
    vector<float> riverWidthes;
    
    vector<ofPolyline> branch01Lines;
    vector<float> branch01Widthes;
    
    vector<ofPolyline> leaf01Lines;
    
    vector<ofPolyline> branch02Lines;
    vector<float> branch02Widthes;
    
    vector<ofPolyline> leaf02Lines;
};
