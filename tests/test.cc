// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/encrypt.h>
#include <catch2/catch.hpp>

using namespace mylibrary;

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}

TEST_CASE("sha", "[random]") {
  string text = "abc";
  mylibrary::SHA1(text);
  REQUIRE(text == "abc");
}

TEST_CASE("simple ceasar", "[ceasar][encrypt][decrypt]") {

  SECTION("encrypt") {
    string input = "abc";
    string output = "bce";
    REQUIRE(input == CeasarChipper(input, 0));
    REQUIRE(output == CeasarChipper(input, 1));
  }

  SECTION("decrypt") {
    string input = "ced";
    string output = "abc";
    REQUIRE(input == DecryptCeasar(input, 0));
    REQUIRE(output == DecryptCeasar(input, 2));
  }
}

TEST_CASE("complex ceasar", "[ceasar][encrypt][decrypt][simple]") {

  SECTION("encrypt") {
    string input = "HellO World! 137";
    string output = "bce";
    REQUIRE(input == CeasarChipper(input, input.size()));
    REQUIRE(output == CeasarChipper(input, 1));
  }

  SECTION("decrypt") {
    string input = "ced";
    string output = "abc";
    REQUIRE(input == DecryptCeasar(input, input.size()));
    REQUIRE(output == DecryptCeasar(input, 2));
  }
}

TEST_CASE("XOR", "[random]") {
  string text = "ali tOpu aT";
  mylibrary::XOR(text, 31);
  REQUIRE(text != "abc");
}