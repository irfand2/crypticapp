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
  // helpers to draw different screens, these are called in draw():
  void DrawMainScreen();
  void DrawEncryptScreen();
  void DrawDecryptScreen();
 private:
  // to keep track of the screen the user is currently in:
  bool in_main_screen;
  bool in_encrypt_screen;
  bool in_decrypt_screen;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
