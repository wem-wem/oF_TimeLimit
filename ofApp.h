
#pragma once
#include "ofMain.h"
#include "PlayerState.h"


class ofApp : public ofBaseApp {
private:
  int frameLate;
  int time_;  // 表示される残り時間
  int frameCount_;
  float fontSize_;
  ofTrueTypeFont font_; // 表示する際のフォントとサイズを入れる箱

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
};
