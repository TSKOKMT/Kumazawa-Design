#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#define STRINGIFY(A) #A

class visual01 {

public:
    visual01();
    
    void draw(ofRectangle frame_, float time_);
    
private:
    ofImage textImage;
    
    //ofVideoGrabber grabber;
    ofVideoPlayer video;
    
    ofShader shader;
    string shaderProgram = STRINGIFY
    (
        uniform sampler2DRect texture;
        uniform sampler2DRect mask;

        void main() {
            vec2 coordinate = gl_FragCoord.xy;

            vec4 color = texture2DRect(texture, coordinate);
            color.a = texture2DRect(mask, coordinate).a;

            gl_FragColor = color;
        }
    );
};
