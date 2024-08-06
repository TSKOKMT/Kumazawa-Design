#include "visual02.h"

//--------------------------------------------------------------
visual02::visual02() {
    
    textImage.load("02/text.png");
    
    ofxSVG svg;
    svg.load("02/river 1.svg");
    auto pathes = svg.getPaths();
    for (int i = 0; i < pathes.size(); i++) {
        pathes[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        riverLines.push_back(pathes[i].getOutline()[0]);
        riverWidthes.push_back(pathes[i].getStrokeWidth());
    }
    
    svg.load("02/branch01.svg");
    pathes = svg.getPaths();
    for (int i = 0; i < pathes.size(); i++) {
        pathes[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        branch01Lines.push_back(pathes[i].getOutline()[0]);
        branch01Widthes.push_back(pathes[i].getStrokeWidth());
    }
    
    svg.load("02/leaf01.svg");
    pathes = svg.getPaths();
    for (int i = 0; i < pathes.size(); i++) {
        pathes[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        leaf01Lines.push_back(pathes[i].getOutline()[0]);
    }
    
    svg.load("02/branch02.svg");
    pathes = svg.getPaths();
    for (int i = 0; i < pathes.size(); i++) {
        pathes[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        branch02Lines.push_back(pathes[i].getOutline()[0]);
        branch02Widthes.push_back(pathes[i].getStrokeWidth());
    }
    
    svg.load("02/leaf02.svg");
    pathes = svg.getPaths();
    for (int i = 0; i < pathes.size(); i++) {
        pathes[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        leaf02Lines.push_back(pathes[i].getOutline()[0]);
    }
}

//--------------------------------------------------------------
void visual02::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //DRAW
    
    ofPushStyle();
    
    ofSetColor(255, 205, 176);
    ofDrawRectangle(frame_);
    
    ofSetColor(255);
    textImage.draw(frame_);
    
    //Leaf 01
    ofNoFill();
    for (int i = 0; i < leaf01Lines.size(); i++) {
        ofSetColor(133, 34, 40);
        ofSetLineWidth(20);
        leaf01Lines[i].draw();
        
        ofSetColor(168, 202, 76);
        ofSetLineWidth(11);
        leaf01Lines[i].draw();
    
        ofSetColor(40, 70, 174);
        ofSetLineWidth(6);
        leaf01Lines[i].draw();
    }
    
    //Branch 01
    ofSetColor(68, 70, 84);
    ofNoFill();
    for (int i = 0; i < riverLines.size(); i++) {
        float theTime = time_ - .1 * i;
        
        float motionB = ofClamp(ofWrap(theTime, 0, 4), 0, 1);
        float motionE = ofClamp(ofWrap(theTime, 0, 4) - 3, 0, 1);
        
        ofSetLineWidth(branch01Widthes[i]);
        ofBeginShape();
        for (int j = 0; j < 100; j++) {
            float ratio = j / 100.;
            ratio = ofLerp(motionB, motionE, ratio);
            ofVertex(branch01Lines[i].getPointAtPercent(ratio));
        }
        ofEndShape();
    }
    
    //Leaf 02
    ofNoFill();
    for (int i = 0; i < leaf02Lines.size(); i++) {
        ofSetColor(95, 25, 113);
        ofSetLineWidth(20);
        leaf02Lines[i].draw();
        
        ofSetColor(202, 163, 66);
        ofSetLineWidth(11);
        leaf02Lines[i].draw();
    
        ofSetColor(44, 174, 101);
        ofSetLineWidth(6);
        leaf02Lines[i].draw();
    }
    
    //Branch 02
    ofSetColor(70, 84, 79);
    ofNoFill();
    for (int i = 0; i < riverLines.size(); i++) {
        float theTime = time_ - .1 * i;
        
        float motionB = ofClamp(ofWrap(theTime, 0, 4), 0, 1);
        float motionE = ofClamp(ofWrap(theTime, 0, 4) - 3, 0, 1);
        
        ofSetLineWidth(branch02Widthes[i]);
        ofBeginShape();
        for (int j = 0; j < 100; j++) {
            float ratio = j / 100.;
            ratio = ofLerp(motionB, motionE, ratio);
            ofVertex(branch02Lines[i].getPointAtPercent(ratio));
        }
        ofEndShape();
    }
    
    //River
    ofSetColor(223, 236, 245);
    ofNoFill();
    for (int i = 0; i < riverLines.size(); i++) {
        float theTime = time_ - .1 * i;
        
        float motionB = ofClamp(ofWrap(theTime, 0, 3), 0, 1);
        float motionE = ofClamp(ofWrap(theTime, 0, 3) - 1, 0, 1);
        
        ofSetLineWidth(riverWidthes[i]);
        ofBeginShape();
        for (int j = 0; j < 100; j++) {
            float ratio = j / 100.;
            ratio = ofLerp(motionB, motionE, ratio);
            ofVertex(riverLines[i].getPointAtPercent(ratio));
        }
        ofEndShape();
    }
    
    ofPopStyle();
}
