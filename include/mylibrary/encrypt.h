// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_


#include <string>

using namespace std;

namespace mylibrary {

// Basic ceasar chipper that shifts the letters in a string by the given key.
void CeasarChipper(string& input, int key);
// Standard XOR encryption.
void XOR(string& input, int key);
// Hashes the input using SHA1 algortihm.
void SHA1(string& input);
// Decrypts strings encrypted with Ceasar.
void DecryptCeasar(string& input, int key);
// Decrypts strings encrypted with XOR.
void DecryptXOR(string& input, int key);

// Hashing is one-way, so no decryption for SHA1.

}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
