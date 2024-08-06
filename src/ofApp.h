#pragma once

#include "ofMain.h"

#include "visual01.h"
#include "visual02.h"
#include "visual03.h"
#include "visual04.h"
#include "visual05.h"
#include "visual06.h"

class ofApp : public ofBaseApp{

public:
    void setup() override;
    void update() override;
    void draw() override;
    void exit() override;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
		
private:
    float time;
    float previousTime;
    
    int index = 4;
    
    visual01 myVisual01;
    visual02 myVisual02;
    visual03 myVisual03;
    visual04 myVisual04;
    visual05 myVisual05;
    visual06 myVisual06;
};
