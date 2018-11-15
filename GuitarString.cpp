#include "GuitarString.hpp"
#include <memory>
#include <vector>
#include <iostream>
// Copyright 2018 <Pitou Teng>

GuitarString::GuitarString(double frequency) {
 this->freq = frequency;
 this->ptrBuffer = new RingBuffer(ceil(SAMP_RATE/this->freq));
 for(int i = 0; i < this->ptrBuffer->size(); i++) {
   this->ptrBuffer->enqueue(0);
 }
 this->ntime = 0;
}

GuitarString::GuitarString(std::vector<sf::Int16> init){
 this->ptrBuffer = new RingBuffer(init.size());
 for (int i = 0; i < init.size(); i++) {
  this->ptrBuffer->enqueue(init[i]);
 }
 this->ntime = 0;
}

void GuitarString::pluck() {
//  if (!this->ptrBuffer->isEmpty()) {
//   delete this->ptrBuffer;
//   this->ptrBuffer = new RingBuffer(ceil(this->freq));
//  }
  while(!(this->ptrBuffer->isEmpty()))
    this->ptrBuffer->dequeue();

 int16_t t;
 while (!this->ptrBuffer->isFull()) {
  t = (rand() % 65536) -32768;
  // t = (rand() % (0-32768)) + 65536;
  this->ptrBuffer->enqueue(t);
 }
}
// need to work on tic and sample, problem with dequeue
void GuitarString::tic() {

  // auto calfreq = [] (double a, double b, int16_t c, int16_t d) {
    
  // };

  ntime++;
  int16_t t = this->ptrBuffer->dequeue();
  this->ptrBuffer->enqueue(DECAY_FACTOR * .5 *(t + this->ptrBuffer->peek()));
}

sf::Int16 GuitarString::sample() {
  auto f = [](int16_t i){
    return i;
  };
  return f(this->ptrBuffer->peek());
}

int GuitarString::time() {
 return this->ntime;
}
