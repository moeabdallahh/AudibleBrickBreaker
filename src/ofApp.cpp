#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    srand(time(NULL));
    ofSetBackgroundColor(0, 0, 0);

    /*-----------BRICK SETTINGS-----------*/

    xmin = 0;
    xmax = ofGetScreenWidth();
    xstep = 50;

    ymin = 50;
    ymax = 150;
    ystep = 50;

    /*-----------BALL VECTOR SETTINGS------------*/

    negvelmin = -15;
    posvelmin = 15;
    velrecx = negvelmin + rand() % posvelmin - negvelmin + 1;
    velrecy = negvelmin + rand() % posvelmin - negvelmin + 1;

    /*-------BALL STARTING POSITION AND SIZE-----------*/

    Ball.set(500, 300, 15, 15);

    /*-------PLATFORM SIZE AND POSITION PARAMETERS-----------*/

    Platform.set(500, 700, 200, 25);

    /*----------SOUND SETUP---------------*/

    Watta.load("watta2.mp3");
    Watta.setVolume(1);

    /*---------2D X AND Y SAMPLING----------*/

    nx = (xmax - xmin) / xstep + 1;

    for (int j = 0; j < nx; j++)
    {
        x[j] = xmin + j * xstep;
    }

    ny = (ymax - ymin) / ystep + 1;

    for (int i = 0; i < ny; i++)
    {
        y[i] = ymin + i * ystep;
    }

    /*---------COLOR AND POSITION SETTING----------*/

    for (int i = 0; i < ny; i++)
    {
        for (int j = 0; j < nx; j++)
        {
            Matrix[i][j] = 1;
            BrickColors[i][j].set(rand() % 255, rand() % 255, rand() % 255);

            Bricks[i][j].set(x[j], y[i], 50, 50);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    /*-----------BALL PHYSICS---------------*/

    Ball.x = Ball.x + velrecx;
    Ball.y = Ball.y + velrecy;

    if (Ball.x + Ball.width > 1024 && velrecx > 0)
    {
        velrecx = -velrecx; //hits right bound, reverse direction
    }

    if (Ball.x < 0 && velrecx < 0)
    {
        velrecx = -velrecx; //hits left bound, reverse direction
    } 

    if (Ball.y + Ball.height > 768 && velrecy > 0)
    {
        velrecy = 0; //hits lowest bound, stop all movement
        velrecx = 0;
    }
    
    if (Ball.y < Ball.height && velrecy < 0)
    {
        velrecy = -velrecy; //hits highest bound, reverse direction
    } 

    b = Platform.inside(Ball.x, Ball.y + Ball.height);
    if (b == 1)
    {
        velrecy = -velrecy; //hits platform, reverse direction
    }
    
    /*-------INTERSECTIONS W/ BALL TO BRICK----------*/

    bool vflag = false;
    for (int i = 0; i < ny; i++)
    {
        for (int j = 0; j < nx; j++)
        {
            I = Bricks[i][j].intersects(Ball);
            if (I == 1 && Matrix[i][j] == 1)
            {
                Matrix[i][j] = 0;
                BrickColors[i][j].set(0,0,0);
                    if (!vflag)
                    {
                        velrecy = -velrecy;
                        Watta.play();
                    }
                vflag = true;  
            }
        }
    }
}
        
//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < ny; i++)
    {
        for (int j = 0; j < nx; j++)
        {
            ofSetColor(BrickColors[i][j]);
            ofDrawRectangle(Bricks[i][j]);
        }
    }

    ofSetColor(255, 255, 255);
    ofDrawRectangle(Platform);
    ofDrawRectangle(Ball);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    /*---------PLATFORM INCREMENTATION----------*/
    if (key == OF_KEY_LEFT)
    {
        Platform.x = Platform.x - 100;

        if (Platform.x <= 0)
        {
            Platform.x = 0;
        }
    }
    if (key == OF_KEY_RIGHT)
    {
        Platform.x = Platform.x + 100;

        if (Platform.x + Platform.width >= 1024)
        {
            Platform.x = 824;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}