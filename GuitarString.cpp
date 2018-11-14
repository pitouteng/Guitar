#include "GuitarString.hpp"
#include <memory>
#include <vector>
// Copyright 2018 <Pitou Teng>

GuitarString::GuitarString(double frequency) {
 this->freq = frequency;
 this->ptrBuffer = std::unique_ptr <RingBuffer> (
  new RingBuffer(ceil(this->freq/44100)));
}

GuitarString::GuitarString(const std::vector<sf::Int16>& init){
 this->ptrBuffer = std::unique_ptr <RingBuffer> (new RingBuffer(init.size()));
 for (int i = 0; i < init.size(); i++) {
  this->ptrBuffer->enqueue(init[i]);
 }
}

void GuitarString::pluck() {
 if (this->ptrBuffer->isFull()) {
  this->ptrBuffer.reset(new RingBuffer(ceil(this->freq)));
 }
 int16_t t = (rand() % 65536) -32768;

 for (int i = 0; i < (this->ptrBuffer)->size(); i++) {
  this->ptrBuffer->enqueue(t);
 }
}


void GuitarString::tic() {
 ntime++;
 int16_t t = this->ptrBuffer->dequeue();
 this->ptrBuffer->enqueue(.996 * .5 *(t + this->ptrBuffer->peek()));
}
sf::Int16 GuitarString::sample() {
 return this->ptrBuffer->peek();
}

int GuitarString::time() {
 return this->ntime;
}
