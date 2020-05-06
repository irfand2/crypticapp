// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
 private:
  void DrawMainScreen();
  void DrawEncryptScreen();
  void DrawDecryptScreen();
 private:
  bool inMainScreen;
  bool inEncryptScreen;
  bool inDecryptScreen;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
