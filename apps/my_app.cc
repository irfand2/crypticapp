// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include "CinderImGui.h"
#include <mylibrary/encrypt.h>

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {
  ImGui::initialize();

  inMainScreen = true;
  inEncryptScreen = false;
  inDecryptScreen = false;

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

void MyApp::DrawMainScreen() {
  cinder::gl::clear();
  ui::Text("Welcome to the Cryptic App!\nWith this app, you can encrypt your texts using:\n"
           "Ceasar Chipping, XOR Encryption, or SHA1 hashing.\nYou can also decrypt texts that"
           "are encrypted with Ceasar and XOR!\n\n\nClick on your desired operation:");
  if (ui::Button("encrypt")) {
    inMainScreen = false;
    inEncryptScreen = true;
  }
  if (ui::Button("decrypt")) {
    inMainScreen = false;
    inDecryptScreen = true;
  }

}

void MyApp::DrawEncryptScreen() {
  cinder::gl::clear();
  ui::Text("Choose your desired encryption method:");
  static bool ceasar_box = false;
  static bool xor_box = false;
  static bool sha_box = false;
  ui::Checkbox("Ceasar Chipper", &ceasar_box);
  ui::Checkbox("XOR Chipper", &xor_box);
  ui::Checkbox("SHA1 Hashing", &sha_box);
  static std::string message;
  ImGui::InputTextMultiline("Enter your text below:", &message);
  static int key = 0;
  ImGui::InputInt("Enter your key here:", &key);
  static std::string encrypted_text = "";
  static bool shouldEncrypt = false;
  ui::Checkbox("ENCRYPT", &shouldEncrypt);
  if (shouldEncrypt) {
    if (ceasar_box) {
      encrypted_text = mylibrary::CeasarChipper(message, key);
    } else if (xor_box) {
      encrypted_text = mylibrary::XOR(message, key);
    } else if (sha_box) {
      encrypted_text = mylibrary::SHA1(message);
    }
    ui::Text(encrypted_text.c_str());
  }
  if (ui::Button("GO BACK")) {
    inEncryptScreen = false;
    inMainScreen = true;
  }
}

void MyApp::DrawDecryptScreen() {
  cinder::gl::clear();
  ui::Text("Choose your desired decryption method:");
  static bool ceasar_box = false;
  static bool xor_box = false;
  ui::Checkbox("Ceasar Chipper", &ceasar_box);
  ui::Checkbox("XOR Chipper", &xor_box);
  static std::string message;
  ImGui::InputTextMultiline("Enter your text below:", &message);
  static int key = 0;
  ImGui::InputInt("Enter your key here:", &key);
  static std::string decrypted_text = "";
  static bool shouldDecrypt = false;
  ui::Checkbox("DECRYPT", &shouldDecrypt);
  if (shouldDecrypt) {
    if (ceasar_box) {
      decrypted_text = mylibrary::DecryptCeasar(message, key);
    } else if (xor_box) {
      decrypted_text = mylibrary::DecryptXOR(message, key);
    }
    ui::Text(decrypted_text.c_str());
  }
  if (ui::Button("GO BACK")) {
    inDecryptScreen = false;
    inMainScreen = true;
  }
}

}  // namespace myapp
