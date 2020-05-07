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

  // initially, user is in main screen
  in_main_screen = true;
  in_encrypt_screen = false;
  in_decrypt_screen = false;

}

void MyApp::update() { }

void MyApp::draw() {
  if (in_main_screen) {
    DrawMainScreen();
  } else if (in_encrypt_screen) {
    DrawEncryptScreen();
  } else if (in_decrypt_screen) {
    DrawDecryptScreen();
  }
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::DrawMainScreen() {
  cinder::gl::clear();
  // an informative text for the user
  ui::Text("Welcome to the Cryptic App!\nWith this app, you can "
           "encrypt your texts using:\n"
           "Ceasar Chipping, XOR Encryption, or SHA1 hashing.\nYou can also "
           "decrypt texts that are encrypted with Ceasar and XOR!"
           "\n\n\nClick on your desired operation:");

  // two buttons for encryption and decryption
  if (ui::Button("encrypt")) {
    in_main_screen = false;
    in_encrypt_screen = true;
  }
  if (ui::Button("decrypt")) {
    in_main_screen = false;
    in_decrypt_screen = true;
  }
}

void MyApp::DrawEncryptScreen() {
  cinder::gl::clear();
  ui::Text("Choose your desired encryption method:");

  // to keep track of chosen method
  static bool ceasar_box = false;
  static bool xor_box = false;
  static bool sha_box = false;

  // create boxes and link them to variables
  ui::Checkbox("Ceasar Chipper", &ceasar_box);
  ui::Checkbox("XOR Chipper", &xor_box);
  ui::Checkbox("SHA1 Hashing", &sha_box);

  // get user input from a textbox
  static std::string message;
  ImGui::InputTextMultiline("Enter your text below:", &message);
  static int key = 0;
  ImGui::InputInt("Enter your key here:", &key);

  static std::string encrypted_text = "";
  static bool should_encrypt = false;

  // encrypt the text with chosen method when clicked
  ui::Checkbox("ENCRYPT", &should_encrypt);
  if (should_encrypt) {
    if (ceasar_box) {
      encrypted_text = mylibrary::CeasarChipper(message, key);
    } else if (xor_box) {
      encrypted_text = mylibrary::XOR(message, key);
    } else if (sha_box) {
      encrypted_text = mylibrary::SHA1(message);
    }
    ui::Text(encrypted_text.c_str());
  }

  // to go back to main screen
  if (ui::Button("GO BACK")) {
    in_encrypt_screen = false;
    in_main_screen = true;
  }
}

void MyApp::DrawDecryptScreen() {
  cinder::gl::clear();
  ui::Text("Choose your desired decryption method:");

  // to keep track of chosen method
  static bool ceasar_box = false;
  static bool xor_box = false;

  // create boxes and link them to variables
  ui::Checkbox("Ceasar Chipper", &ceasar_box);
  ui::Checkbox("XOR Chipper", &xor_box);

  // get user input from a textbox
  static std::string message;
  ImGui::InputTextMultiline("Enter your text below:", &message);
  static int key = 0;
  ImGui::InputInt("Enter your key here:", &key);

  static std::string decrypted_text = "";
  static bool should_decrypt = false;

  // decrypt the text with chosen method when clicked
  ui::Checkbox("DECRYPT", &should_decrypt);
  if (should_decrypt) {
    if (ceasar_box) {
      decrypted_text = mylibrary::DecryptCeasar(message, key);
    } else if (xor_box) {
      decrypted_text = mylibrary::DecryptXOR(message, key);
    }
    ui::Text(decrypted_text.c_str());
  }

  // to go back to main screen
  if (ui::Button("GO BACK")) {
    in_decrypt_screen = false;
    in_main_screen = true;
  }
}

}  // namespace myapp
