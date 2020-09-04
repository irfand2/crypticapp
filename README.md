# A Cryptic App

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

**Description**

This is a simple cryptography project that provides 3 encryption methods:
Ceasar Cipher, XOR, SHA1 hashing. Decryptors for Ceasar and XOR are also provided.
The UI is very simple, and thus the app is easy to use. This app is great for ordinary
people who want to keep their files/texts from easy access by normal people (not hackers
or crypto experts), ie. for those who don't need overly complex algorithms.

**Dependencies/Libraries Used**
   - Cmake
   - Visual Studio 2015
   - Cinder
   - Cinder-SHA1 block (for SHA1 hashing)
   - Cinder-ImGui (for UI)
   
**How to use this program:**

Just start the program, choose encryption or decryption, enter your text and key,
choose a method, and receive your encrypted/decrypted text!

**Why there is no decryption support for SHA1?**

Because hashing is one way! Hash functions are (or at least should be) easy
to calculate, but near-impossible to reverse.

For more info on this topic:
https://en.wikipedia.org/wiki/Hash_function

**Which method is more appropriate for "xxx" ?**

Ceasar is the easiest to crack, as it just shifts characters. So use it only 
against people with little-to-none techincal backgrounds.
Ex: You are sending texts to your friends and don't want your teacher to read it!

XOR is quite difficult to crack without the key, so use it when you need a stronger
encryption method but the info will be to converted back to original by someone
at some point (ie. you don't want it to be permanent).

Use SHA1 hashing when you know the people you send the encrypted message to will not
(or should not) be decrypting it but just check if their text is the same as your message.

For more info about encryption :
https://en.wikipedia.org/wiki/Encryption
   

**Author**: Irfan Demetoglu - [`irfand2@illinois.edu`](mailto:irfand2@illinois.edu)



