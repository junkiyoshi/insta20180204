#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	float radius_span = 15;
	for (float radius = radius_span; radius < ofGetWidth() / 2; radius += radius_span) {

		ofColor color;
		color.setHsb(ofMap(radius, radius_span, ofGetWidth() / 2, 0, 255), 255, 255);
		ofSetColor(color);

		float noise_value = ofNoise(radius * 0.0005 - ofGetFrameNum() * 0.001) * 360;
		float x = radius * cos(noise_value);
		float y = radius * sin(noise_value);

		ofDrawCircle(x, y, 15);
	}


	this->cam.end();
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}