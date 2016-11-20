
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

  gui_.setup();
  gui_.add(fontScale_.setup("FontSize", 100, 0, 1000));

  ofLog() << fontSize_;
  ofLog() << limit_;

  ofAddListener(ofEvents().update, this, &Timer::update);
  ofAddListener(ofEvents().draw, this, &Timer::draw);
}

void Timer::update(ofEventArgs &args) {}

void Timer::draw(ofEventArgs &args) {
  drawTimer();
  gui_.draw();
}

// �t�H���g�ǂݍ���
void Timer::fontSetup() {
  loadFontSize();
  font_.loadFont("consolab.ttf", fontSize_);
}

// xml�t�@�C�����琧�����Ԃ̍ő�l�����[�h
void Timer::loadMaxTime() {
  if (xml_.loadFile("Game/timer_settings.xml")) {
    setMaxTime(xml_.getValue("Game:TimeLimit:MaxTime", 0));
    resetLimit(); // �ő�l�̃��[�h�Ɠ����ɐ������Ԃɓ����l����
  }
}

// xml�t�@�C������t�H���g�T�C�Y�̃��[�h
void Timer::loadFontSize() {
  if (xml_.loadFile("Game/timer_settings.xml")) {
    setFontSize(xml_.getValue("Game:TimeLimit:FontSize", 0));
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

  ofTranslate(ofGetWidth()/2, 0);
  ofScale((ofGetWidth() / fontScale_), (ofGetHeight() / fontScale_), 1);

  font_.drawString(text, -fontWidth/2, fontHeight);
  ofPopMatrix();
}

void Timer::saveFile(int key) {
  if (key == 's') {
    gui_.saveToFile("Game/TimerSize.xml");
  }
  else if (key == 'l') {
    gui_.loadFromFile("Game/TimerSize.xml");
  }
}

