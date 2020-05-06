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
  void mouseDown(cinder::app::MouseEvent) override;
 private:
  void DrawMainScreen();
  void DrawEncryptScreen();
  void DrawDecryptScreen();
 private:

  const std::string kEncryptButtonLabel = "ENCRYPT";
  const std::string kDecryptButtonLabel = "DECRYPT";

  const std::string kEncryptButtonText = "ENCRYPT";
  const std::string kDecryptButtonText = "DECRYPT";

  const std::string kEncryptInfoText = "Enter your text here:";
  const std::string kEncryptKeyText = "Enter your key here:";
  const std::string kEncryptChoicesText = "Choose an encryption method";

  const std::string kDecryptInfoText = "Enter your chipped text here:";
  const std::string kDecryptKeyText = "Enter the key of encryption here:";

  bool inMainScreen;
  bool inEncryptScreen;
  bool inDecryptScreen;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
