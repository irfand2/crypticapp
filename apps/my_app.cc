// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>


namespace myapp {

using cinder::app::KeyEvent;
using cinder::Rectf;
using cinder::vec2;
using cinder::Color;


Rectf encrypt_button;
Rectf decrypt_button;
Color encrypt_color;
Color decrypt_color;


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
  vec2 c = getWindowCenter();
  encrypt_button = Rectf(c.x - 250, c.y + 50, c.x + 250, c.y + 200);
  encrypt_color = Color(0,1,0);
  decrypt_button = Rectf(c.x - 250, c.y-200, c.x + 250, c.y-50);
  decrypt_color = Color(1,0,0);
}

void MyApp::update() { }

void MyApp::draw() {
  cinder::gl::clear();

  cinder::gl::color(encrypt_color);
  cinder::gl::drawSolidRect(encrypt_button);

  cinder::gl::color(decrypt_color);
  cinder::gl::drawSolidRect(decrypt_button);
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
