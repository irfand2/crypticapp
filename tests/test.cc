// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/encrypt.h>
#include <catch2/catch.hpp>

using namespace mylibrary;

// the reason my keys in tests are 1 is I calculated the encrypted version
// myself, so chose 1 for convenience

TEST_CASE("simple ceasar", "[ceasar][encrypt][decrypt]") {

  SECTION("encrypt") {
    string input = "abc";
    string output = "bcd";
    REQUIRE(input == CeasarChipper(input, 0));
    REQUIRE(output == CeasarChipper(input, 1));
  }

  SECTION("decrypt") {
    string input = "cde";
    string output = "abc";
    REQUIRE(input == DecryptCeasar(input, -4));
    REQUIRE(output == DecryptCeasar(input, 2));
  }
}

TEST_CASE("complex ceasar", "[ceasar][encrypt][decrypt]") {

  SECTION("encrypt") {
    string input = "HellO World! 137";
    string output = "IfmmP!Xpsme\"!248";
    REQUIRE(input == CeasarChipper(input, input.size()));
    REQUIRE(output == CeasarChipper(input, 1));
  }

  SECTION("decrypt") {
    string input = "IfmmP!Xpsme\"!248";
    string output = "HellO World! 137";
    REQUIRE(input == DecryptCeasar(input, input.size()));
    REQUIRE(output == DecryptCeasar(input, 1));
  }
}

TEST_CASE("simple xor", "[xor][encrypt][decrypt]") {

  SECTION("encrypt") {
    string input = "abc";
    string output = "`cb";
    REQUIRE(input == XOR(input, 0));
    REQUIRE(output == XOR(input, 1));
  }

  SECTION("decrypt") {
    string input = "`cb";
    string output = "abc";
    REQUIRE(input == DecryptXOR(input, 0));
    REQUIRE(output == DecryptXOR(input, 1));
  }
}

TEST_CASE("complex xor", "[xor][encrypt][decrypt]") {

  SECTION("encrypt") {
    string input = "HellO World! 137";
    string output = "IdmmN!Vnsme !026";
    REQUIRE(input == XOR(input, -3));
    REQUIRE(output == XOR(input, 1));
  }

  SECTION("decrypt") {
    string input = "IdmmN!Vnsme !026";
    string output = "HellO World! 137";
    REQUIRE(input == DecryptXOR(input, -12));
    REQUIRE(output == DecryptXOR(input, 1));
  }
}

TEST_CASE("simple sha", "[sha][encrypt]") {

  SECTION("encrypt") {
    string input = "abc";
    string output = "a9993e364706816aba3e25717850c26c9cd0d89d";
    REQUIRE(output == SHA1(input));
  }
}
