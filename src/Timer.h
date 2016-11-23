
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include <chrono>


class Timer {
private:
  int limit_;  // 表示される残り時間
  //int maxTime_;
  float startTime_; // 計測開始時の時間を保存
  float fontSize_;
  ofTrueTypeFont font_; // 表示する際のフォントとサイズを入れる箱
  ofxXmlSettings xml_;

  // 以下gui用
  ofxPanel gui_;
  ofxFloatSlider fontScale_;
  ofxIntSlider maxTime_;
  ofxButton save_;
  ofxButton load_;

  void guiSetup();
  void fontSetup();
  void loadMaxTime();
  void loadFontSize();
  void resetLimit();
  void drawTimer();
  void saveFile();
  void loadFile();
public:
  void setLimit(int time);
  int getLimit();

  void setMaxTime(int maxTime);
  int getMaxTime();

  void setFontSize(int fontSize);
  int getFontSize();

  void setup();
  void draw();
};
