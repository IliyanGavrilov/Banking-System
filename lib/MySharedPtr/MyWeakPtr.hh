#pragma once
#include "MySharedPtr.hh"

template <class T>
class MyWeakPtr {
  T* data = nullptr;
  Counter* counter = {};

  void free() {
    if(data == nullptr && counter == nullptr) {
      return;
    }

    counter->removeMyWeakPtr();
    if(counter->getWeakCount() == 0) { // Use count is also 0
      delete counter;
    }
  }

  void copyFrom(const MyWeakPtr<T>& other) {
    data = other.data;
    counter = other.counter;

    if(counter) {
      counter->addMyWeakPtr();
    }
  }

  void moveFrom(MyWeakPtr<T>&& other) noexcept {
    data = other.data;
    other.data = nullptr;

    counter = other.counter;
    other.counter = nullptr;
  }

public:
  MyWeakPtr() {
    data = nullptr;
    counter = nullptr;
  }

  MyWeakPtr(MySharedPtr<T>& ptr) { // NOT EXPLICIT
    data = ptr.data;
    counter = ptr.counter;

    if(counter) {
      counter->addMyWeakPtr();
    }
  }

  MyWeakPtr(const MyWeakPtr<T>& other) {
    copyFrom(other);
  }

  MyWeakPtr(MyWeakPtr<T>&& other) noexcept {
    moveFrom(std::move(other));
  }

  ~MyWeakPtr() {
    free();
  }

  MyWeakPtr& operator=(const MyWeakPtr<T>& other) {
    if(this != &other) {
      free();
      copyFrom(other);
    }

    return *this;
  }


  MyWeakPtr& operator=(MyWeakPtr<T>&& other) noexcept {
    if(this != &other) {
      free();
      moveFrom(std::move(other));
    }

    return *this;
  }


  MySharedPtr<T> lock() const {
    if(expired()) {
      return MySharedPtr<T>();
    }
    else {
      return MySharedPtr<T>(data);
    }
  }

  bool expired() const {
    return counter && counter->getUseCount() == 0;
  }
};