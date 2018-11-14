#ifndef GUITARSTRING_HPP
#define GUITARSTRING_HPP
// Copyright 2018 <Pitou Teng>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "RingBuffer.hpp"

// using namespace std;
// using namespace sf;
class GuitarString {
 public:
  explicit GuitarString(const  double &frequency);
  explicit GuitarString(const std::vector<sf::Int16> init);
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();
 private:
  // const int sampRate = 441000;
  double freq;
  std::unique_ptr <RingBuffer> ptrBuffer;
  int ntime;
};
#endif
