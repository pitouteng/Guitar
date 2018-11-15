// copyright pitou teng 2018

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100
#define NUM_KEY 37

std::vector<sf::Int16> makeSamplesFromString(GuitarString gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
    int keys [NUM_KEY] = {
      sf::Keyboard::Q,
      sf::Keyboard::Num2,
      sf::Keyboard::W,
      sf::Keyboard::E,
      sf::Keyboard::Num4,
      sf::Keyboard::R,
      sf::Keyboard::Num5,
      sf::Keyboard::T,
      sf::Keyboard::Y,
      sf::Keyboard::Num7,
      sf::Keyboard::U,
      sf::Keyboard::Num8,
      sf::Keyboard::I,
      sf::Keyboard::Num9,
      sf::Keyboard::O,
      sf::Keyboard::P,
      sf::Keyboard::Subtract,
      sf::Keyboard::LBracket,
      sf::Keyboard::Equal,
      sf::Keyboard::Z,
      sf::Keyboard::X,
      sf::Keyboard::D,
      sf::Keyboard::C,
      sf::Keyboard::F,
      sf::Keyboard::V,
      sf::Keyboard::G,
      sf::Keyboard::B,
      sf::Keyboard::N,
      sf::Keyboard::J,
      sf::Keyboard::M,
      sf::Keyboard::K,
      sf::Keyboard::Comma,
      sf::Keyboard::Period,
      sf::Keyboard::SemiColon,
      sf::Keyboard::Slash,
      sf::Keyboard::Quote,
      sf::Keyboard::Space
    };
  std::vector<sf::Int16> audio_samp_vec;
  std::vector<sf::SoundBuffer> sound_buffer_vec;
  std::vector<sf::Sound> sound_vec;

  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero Lite");
  sf::Event event;
  double freq;
  std::vector<sf::Int16> samples;

  // we're reusing the freq and samples vars, but
  // there are separate copies of GuitarString, SoundBuffer, and Sound
  //   for each note
  //
  // GuitarString is based on freq
  // samples are generated from GuitarString
  // SoundBuffer is loaded from samples
  // Sound is set to SoundBuffer

  freq = CONCERT_A;
  sf::Sound sound;
  sf::SoundBuffer buf;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        int i;
        for(i = 0; i < 37; i++) 
          if(keys[i] == event.key.code) {
            double freq = CONCERT_A * (std::pow(2,((i-24.0)/12.0)));
            GuitarString gs = GuitarString(freq);
            samples = makeSamplesFromString(gs);
            if (!buf.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
            throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
            sound.setBuffer(buf);
            sound.play();
            break;
        break;
      // default:
      //   break;
      }

      window.clear();
      window.display();
      }
    }
  }
  return 0;
}
