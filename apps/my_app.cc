// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>


namespace myapp {

using cinder::app::KeyEvent;
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
  /*
   anan = vec2(0,100);
  baban = vec2(0, 100);
  //vec2 amk = getWindowP
  rectangle = Rectf(anan, baban);
  color = Color(1, 0, 0);
  rec = Rectf(getWindowPosX(), getWindowPosY(), getWindowPosX() + 50, getWindowPosY()+ 50);
   */
  //c = getWindowCenter();
  vec2 kCenter = cinder::app::getWindowCenter();
  encrypt_button = Rectf(kCenter.x - 250, kCenter.y + 50, kCenter.x + 250, kCenter.y + 200);
  encrypt_color = Color(0,1,0);
  decrypt_button = Rectf(kCenter.x - 250, kCenter.y-200, kCenter.x + 250, kCenter.y-50);
  decrypt_color = Color(1,0,0);

  button_text_color = Color(0,0,1);
}

void MyApp::update() { }

void MyApp::draw() {
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

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
