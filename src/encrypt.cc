// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/encrypt.h>

#include <string>

#include "sha1.h"

using namespace std;

namespace mylibrary {

const string kCharacters = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void CeasarChipper(string& input, int key) {
  int shift = key % input.size();
  if (shift == 0) {
    return;
  }
  // iterate through the string and shift the letters
  for (int i = 0; i < input.size(); i++) {
    // find the index of the character
    int index = kCharacters.find(input[i]);
    // perform the shift
    index += shift;
    input[i] = kCharacters[index];
  }
}

void XOR(string& input, int key) {
  // iterate and use ^ operator to xor all chars
  for (int i = 0; i < input.size(); i++) {
    input[i] = input[i] ^ key;
  }
}

void SHA1(string& input) {
  // use Cinder-SHA1 library to hash the string
  warp::SHA1 anan;
  anan.update(input);
  input = anan.final();
}

}  // namespace mylibrary
