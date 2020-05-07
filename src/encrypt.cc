// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/encrypt.h>

#include <string>

#include "sha1.h"

using namespace std;

namespace mylibrary {

const string kCharacters = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO"
                           "PQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

string CeasarChipper(string input, int key) {
  if (input.size() == 0 || key < 0) {
    return input;
  }
  int shift = key % kCharacters.size();
  if (shift == 0) {
    return input;
  }
  // iterate through the string and shift the letters
  for (int i = 0; i < input.size(); i++) {
    // find the index of the character
    int index = kCharacters.find(input[i]);
    // perform the shift
    index += shift;
    index = index % kCharacters.size();
    input[i] = kCharacters[index];
  }
  return input;
}

string XOR(string input, int key) {
  if (input.size() == 0 || key < 0) {
    return input;
  }
  // iterate and use ^ operator to xor all chars
  for (int i = 0; i < input.size(); i++) {
    input[i] = input[i] ^ key;
  }
  return input;
}

string SHA1(string input) {
  if (input.size() == 0) {
    return input;
  }
  // use Cinder-SHA1 library to hash the string
  warp::SHA1 sha_1;
  sha_1.update(input);
  input = sha_1.final();
  return input;
}

string DecryptCeasar(string input, int key) {
  if (input.size() == 0 || key < 0) {
    return input;
  }
  int shift = key % kCharacters.size();
  if (shift == 0) {
    return input;
  }
  // iterate through the string and shift the letters
  for (int i = 0; i < input.size(); i++) {
    // find the index of the character
    int index = kCharacters.find(input[i]);
    // perform the shift
    index = index - shift;
    if (index < 0) {
      index = index + kCharacters.size();
    }
    input[i] = kCharacters[index];
  }
  return input;
}

string DecryptXOR(string input, int key) {
  if (input.size() == 0 || key < 0) {
    return input;
  }
  // calling XOR a second time with same values reverses encryption
  return XOR(input, key);
}

}  // namespace mylibrary
