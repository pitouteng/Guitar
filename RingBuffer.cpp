
// Copyright [2018] <Pitou Teng>

#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
  if (capacity >= 1) {
    this->capacity = capacity;
  } else {
    throw std::invalid_argument(
    "RB constructor: capacity must be greater than zero.");
  }
}
// return number of items currently in the buffer
int RingBuffer::size() {
  return this->buffer.size();
}

// is the buffer empty (size equals zero)?
bool RingBuffer::isEmpty() {
  auto e = [] (int i) {
    return i == 0 ? true : false;
  };
  return e(this->size());
}

// is the buffer full (size equals capacity)?
bool RingBuffer::isFull() {
  return this->buffer.size() == this->capacity ? true: false;
}
// add item x to the end
void RingBuffer::enqueue(int16_t x) {
  if (!isFull())
    this->buffer.push(x);
  else
    throw std::runtime_error("enqueue: can't enqueue to a full ring");
}

// delete and return item from the front
int16_t RingBuffer::dequeue() {
  if (this->buffer.size() > 0) {
    int16_t x = this->buffer.front();
    this->buffer.pop();
    return x;
  } else {
    throw std::runtime_error("dequeue: can't dequeue an empty ring");
  }
}

// return (but do not delete) item from the front
int16_t RingBuffer::peek() {
  if (this->buffer.size() > 0)
    return this->buffer.front();
  else
    throw std::runtime_error("peek: can't peek an empty ring");
}
