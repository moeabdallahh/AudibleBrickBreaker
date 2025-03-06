#pragma once

#include "ofMain.h"

#define N_MAX 500

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	float velrecx;
	float velrecy;

	float recvy;
	float recvx;

	float nx;
	float xmin;
	float xmax;
	float xstep;

	float ny;
	float ymin;
	float ymax;
	float ystep;

	int negvelmin;
	int posvelmin;

	bool b;
	bool I;
	bool Matrix[100][100];

	ofSoundPlayer Watta;
	ofSoundPlayer Lose;
	ofSoundPlayer Suck;

	float x[N_MAX];
	float y[N_MAX];

	ofRectangle Bricks[100][100];
	ofRectangle Platform;
	ofRectangle Ball;
	ofColor BrickColors[100][100];

};
