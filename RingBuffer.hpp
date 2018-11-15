#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

// Copyright [2018] <Pitou Teng>

#include <stdint.h>
#include <stdexcept>
#include <queue>
class RingBuffer {
 private:
  std::queue <int16_t> buffer;
  int capacity;
public:
  // create an empty ring buffer, with given max capacity
  explicit RingBuffer(int capacity);
  int size();  // return number of items currently in the buffer
  bool isEmpty();  // is the buffer empty (size equals zero)?
  bool isFull();  // is the buffer full (size equals capacity)?
  void enqueue(int16_t x);  // add item x to the end
  int16_t dequeue();  // delete and return item from the front
  int16_t peek();  // return (but do not delete) item from the front
};

#endif

