
#include "Timer.h"


void Timer::setMaxTime(int maxTime) { maxTime_ = maxTime; }
int Timer::getMaxTime() { return maxTime_; }

void Timer::setLimit(int limit) { limit_ = limit; }
int Timer::getLimit() { return limit_; }

void Timer::setFontSize(int fontSize) { fontSize_ = fontSize; }
int Timer::getFontSize() { return fontSize_; }

void  Timer::setup() {
  fontSetup();
  loadMaxTime();
  guiSetup();
}

void Timer::draw() {
  drawTimer();
  gui_.draw();
}

void Timer::guiSetup() {
  save_.addListener(this, &Timer::saveFile);
  load_.addListener(this, &Timer::loadFile);

  gui_.setup();
  gui_.add(fontScale_.setup("FontScale", 100, 0, 1000));
  gui_.add(maxTime_.setup("MaxTime", 60, 0, 99));
  gui_.add(save_.setup("Save_To_File"));
  gui_.add(load_.setup("Loda_From_File"));
  // xml�ɃZ�[�u���Ă���l���ŏ��ɌĂяo���Ă���
  gui_.loadFromFile("Game/TimerSettings.xml");
}

// �t�H���g�ǂݍ���
void Timer::fontSetup() {
  loadFontSize();
  font_.loadFont("consolab.ttf", fontSize_);
}

// xml�t�@�C�����琧�����Ԃ̍ő�l�����[�h
void Timer::loadMaxTime() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setMaxTime(xml_.getValue("group:MaxTime", 0));
    resetLimit(); // �ő�l�̃��[�h�Ɠ����ɐ������Ԃɓ����l����
  }
}

// xml�t�@�C������t�H���g�T�C�Y�̃��[�h
void Timer::loadFontSize() {
  if (xml_.loadFile("Game/TimerSettings.xml")) {
    setFontSize(xml_.getValue("group:FontSize", 0));
  }
}

// �o�ߎ��Ԃɐ������Ԃ̍ő�l����(�������ŏ��ɌĂяo���z��)
void Timer::resetLimit() {
  setLimit(maxTime_);
}

// ��ʏ㕔�A�Z���^�[�ɕ\��
void Timer::drawTimer() {
  ofPushMatrix();
  ofSetColor(255, 255, 0);
  string text = ofToString((int)(limit_ - (ofGetElapsedTimef() - startTime_)));
  float fontWidth = font_.stringWidth(text);
  float fontHeight = font_.stringHeight(text);

  ofTranslate(ofGetWidth() / 2, 0);
  ofScale((ofGetWidth() / fontScale_), (ofGetHeight() / fontScale_), 1);

  font_.drawString(text, -fontWidth / 2, fontHeight);
  ofPopMatrix();
}

void Timer::saveFile() {
  gui_.saveToFile("Game/TimerSettings.xml");
}

void Timer::loadFile() {
  gui_.loadFromFile("Game/TimerSettings.xml");
}
