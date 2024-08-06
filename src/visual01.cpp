#include "visual01.h"

//--------------------------------------------------------------
visual01::visual01() {
    
    textImage.load("01/text.png");
    
    //grabber.initGrabber(1920, 1080);
    
    video.load("01/video.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    video.setVolume(0);
    video.play();
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
}

//--------------------------------------------------------------
void visual01::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    auto frameM = ofRectangle(frame_.width * (45 / 1920.), frame_.height * (144 / 1080.), frame_.width * (1830 / 1920.), frame_.height * (880 / 1080.));
    
    float spacing = 2.2 * unit;
    
    auto framesH = HStack::get(frameM, 3, spacing);
    
    vector<ofRectangle> frames;
    for (int h = 0; h < framesH.size(); h++) {
        if (ofNoise(time_, h * PI + PI) < .3) {
            auto framesV = VStack::get(framesH[h], 2, spacing);
            for (int v = 0; v < framesV.size(); v++) {
                frames.push_back(framesV[v]);
            }
        }
        else {
            frames.push_back(framesH[h]);
        }
    }
    
    //Make mask
    ofFbo maskFbo;
    maskFbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    maskFbo.begin();
    ofClear(0);
    for (int i = 0; i < frames.size(); i++) {
        auto f = frames[i];
        ofPushMatrix();
        ofTranslate(f.getCenter());
        ofRotateRad(ofSignedNoise(time_ / 6., i) * PI / 8.);
        ofDrawEllipse(0, 0, f.width, f.height);
        ofPopMatrix();
    }
    maskFbo.end();
    
    //Video fbo
    ofFbo videoFbo;
    videoFbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    videoFbo.begin();
    ofClear(0);
    ofSetColor(207, 217, 216);
    video.update();
    video.draw(0, 0, frame_.width, frame_.height);
    videoFbo.end();
    
    //Update grabber
    //grabber.update();
    
    //DRAW
    
    ofPushStyle();
    
    ofSetColor(143, 217, 13);
    ofDrawRectangle(frame_);
    
    ofSetColor(255);
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    shader.begin();
    shader.setUniformTexture("texture", video.getTexture(), 0);
    shader.setUniformTexture("mask", maskFbo.getTexture(), 1);
    ofDrawRectangle(0, 0, frame_.width, frame_.height);
    shader.end();
    fbo.end();
    fbo.draw(frame_.position);
    
    ofSetColor(255);
    textImage.draw(frame_);
    
    ofPopStyle();
}
