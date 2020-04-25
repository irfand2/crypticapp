// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/encrypt.h>

#include <catch2/catch.hpp>

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

TEST_CASE("ceasar", "[random]") {
  string text = "abc";
  mylibrary::CeasarChipper(text, 1);
  REQUIRE(text == "bcd");
}

TEST_CASE("XOR", "[random]") {
  string text = "ali tOpu aT";
  mylibrary::XOR(text, 31);
  REQUIRE(text != "abc");
}