#ifndef GUITARSTRING_HPP
#define GUITARSTRING_HPP
// Copyright 2018 <Pitou Teng>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "RingBuffer.hpp"

using namespace std;
// using namespace sf;
class GuitarString {
 private:
  // const int sampRate = 441000;
  double freq;
  unique_ptr <RingBuffer> ptrBuffer;
  int ntime;
 public:
  GuitarString(double frequency);
  GuitarString(vector<sf::Int16> init);
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();
};
#endif
