#pragma once
#include <iostream> // move, size_t
#include "MyVector.hh"

template <class T>
class MyQueue {
  MyVector<T> data={};

public:
  MyQueue()=default;

  void push(const T& obj) {
    data.push_back(obj);
  }

  void push(T&& obj) {
    data.push_back(std::move(obj));
  }

  void pop() {
    if(isEmpty()) {
      throw std::logic_error("Empty queue!");
    }

    data.pop_front();
  }

  const T& peek() const {
    if(isEmpty()) {
      throw std::logic_error("Empty queue!");
    }

    return data[0];
  }

  bool isEmpty() const {
    return data.empty();
  }
};
