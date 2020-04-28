// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>


namespace myapp {

using cinder::app::KeyEvent;
using cinder::app::MouseEvent;
using cinder::Rectf;
using cinder::vec2;
using cinder::Color;
using cinder::TextBox;


Rectf encrypt_button;
Rectf decrypt_button;
Color encrypt_color;
Color decrypt_color;
Color button_text_color;


vec2 kCenter;


MyApp::MyApp() { }

void MyApp::setup() {

  inMainScreen = true;
  inEncryptScreen = false;
  inDecryptScreen = false;

  vec2 kCenter = cinder::app::getWindowCenter();

  encrypt_button = Rectf(kCenter.x - 250, kCenter.y + 50, kCenter.x + 250, kCenter.y + 200);
  encrypt_color = Color(0,1,0);

  decrypt_button = Rectf(kCenter.x - 250, kCenter.y-200, kCenter.x + 250, kCenter.y-50);
  decrypt_color = Color(1,0,0);

  button_text_color = Color(0,0,1);
}

void MyApp::update() { }

void MyApp::draw() {
  if (inMainScreen) {
    DrawMainScreen();
  } else if (inEncryptScreen) {
    DrawEncryptScreen();
  } else if (inDecryptScreen) {
    DrawDecryptScreen();
  }
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::mouseDown(MouseEvent event)  {
  if (event.isLeft() && event.getX() > kCenter.x - 250 && event.getX() < kCenter.x + 250) {
    if (event.getY() > kCenter.y + 50 && event.getY() < kCenter.y + 200) {
      inMainScreen = false;
      inEncryptScreen = true;
      inDecryptScreen = false;
    } else if (event.getY() > kCenter.y - 200 && event.getY() < kCenter.y - 50) {
      inMainScreen = false;
      inEncryptScreen = false;
      inDecryptScreen = true;
    }
  }
}

void MyApp::DrawMainScreen() {
  cinder::gl::clear();

  cinder::gl::color(encrypt_color);
  cinder::gl::drawSolidRect(encrypt_button);

  cinder::gl::color(decrypt_color);
  cinder::gl::drawSolidRect(decrypt_button);

  vec2 encrypt_text_pos = vec2(kCenter.x + 400, kCenter.y + 250);
  cinder::gl::drawStringCentered(encrypt_button_text, encrypt_text_pos, button_text_color, cinder::Font("Arial", 60));

  vec2 decrypt_text_pos = vec2(kCenter.x + 400, kCenter.y + 500);
  cinder::gl::drawStringCentered(decrypt_button_text, decrypt_text_pos, button_text_color, cinder::Font("Arial", 60));

}

void MyApp::DrawEncryptScreen() {
  cinder::gl::clear();
}

void MyApp::DrawDecryptScreen() {
  cinder::gl::clear();
}

}  // namespace myapp
