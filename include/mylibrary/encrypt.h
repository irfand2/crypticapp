// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_


#include <string>

using namespace std;

namespace mylibrary {

// Basic ceasar chipper that shifts the letters in a string by the given key.
string CeasarChipper(string input, int key);
// Standard XOR encryption.
string XOR(string input, int key);
// Hashes the input using SHA1 algortihm.
string SHA1(string input);
// Decrypts strings encrypted with Ceasar.
string DecryptCeasar(string input, int key);
// Decrypts strings encrypted with XOR.
string DecryptXOR(string input, int key);

// Hashing is one-way, so no decryption for SHA1.

}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
