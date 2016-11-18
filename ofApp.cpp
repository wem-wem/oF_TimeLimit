
#include "ofApp.h"

void ofApp::setup() {
  frameLate = 30;

  ofSetWindowShape(600, 400);
  ofSetFrameRate(frameLate);
  
  time_ = 99;
  fontSize_ = 72.0f;

  // �t�H���g�̓ǂݍ���
  font_.loadFont("consolab.ttf", fontSize_);
}

void ofApp::update() {
  if (time_ > 0) {
    frameCount_++;
  }
  else {
    // ���Ԑ؂�
  }

  if (frameCount_ >= frameLate) {
    time_--;
    frameCount_ = 0;
  }
}

void ofApp::draw() {
  // �^�C�}�[�\��
  ofPushMatrix();
  ofSetColor(255, 255, 0);

  // ��ʏ㕔�A�Z���^�[�ɕ����\��
  font_.drawString(to_string(time_), (ofGetWindowWidth()*0.5) - (fontSize_*0.5), fontSize_);
  ofPopMatrix();
}

void ofApp::keyPressed(int key) {}

void ofApp::keyReleased(int key) {}

void ofApp::mouseMoved(int x, int y) {}

void ofApp::mouseDragged(int x, int y, int button) {}

void ofApp::mousePressed(int x, int y, int button) {}

void ofApp::mouseReleased(int x, int y, int button) {}

void ofApp::mouseEntered(int x, int y) {}

void ofApp::mouseExited(int x, int y) {}

void ofApp::windowResized(int w, int h) {}

void ofApp::gotMessage(ofMessage msg) {}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
