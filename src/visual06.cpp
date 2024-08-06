#include "visual06.h"

//--------------------------------------------------------------
visual06::visual06() {
    
    textImage.load("06/text.png");
    
    ofxSVG svg;
    svg.load("06/letters.svg");
    pathes = svg.getPaths();
}

//--------------------------------------------------------------
void visual06::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    previousTime = time;
    time = time_;
    
    //Change speed
    speed = floor(ofNoise(time_) * 5) / 5. * 200;
    
    //Slide
    for (int i = 0; i < bornPathes.size(); i++) {
        bornPathes[i].translate(ofPoint((time_ - previousTime) * speed * unit, 0));
    }
    
    //Kill
    int i = 0;
    while (i < bornPathes.size()) {
        ofPath thePath = bornPathes[i];
        thePath.setPolyWindingMode(OF_POLY_WINDING_ODD);
        if (thePath.getOutline()[0].getCentroid2D().x > frame_.width * 1.1) bornPathes.erase(bornPathes.begin() + i);
        else i++;
    }
    
    //Bear
    if (ofNoise(time_ * 10000) < .5) bear(ofRandom(pathes.size()));
    
    //DRAW
    
    ofSetColor(0);
    ofDrawRectangle(frame_);
    
    for (int i = 0; i < bornPathes.size(); i++) {
        bornPathes[i].draw();
    }
    
    ofSetColor(255);
    textImage.draw(frame_);
}

//--------------------------------------------------------------
void visual06::bear(int index_) {
    
    if (index_ < 0 || index_ >= pathes.size()) return;
    
    bornPathes.push_back(pathes[index_]);
}
