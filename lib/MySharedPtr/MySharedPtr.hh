#pragma once
#include <iostream> // std::move
#include "Counter.hh"

template <class T>
class MySharedPtr {
  template <class U> friend class MyWeakPtr;

  T* data = nullptr;
  Counter* counter = {};

  void free() {
    if(data == nullptr && counter == nullptr) {
      return;
    }

    counter->removeSharedPtr();

    if(counter->getUseCount() == 0) {
      delete data;
    }

    if(counter->getWeakCount() == 0) {
      delete counter;
    }
  }

  void copyFrom(const MySharedPtr<T>& other) {
      data = other.data;
      counter = other.counter;

      if(counter) {
        counter->addSharedPtr();
      }
    }

  void moveFrom(MySharedPtr<T>&& other) noexcept {
    data = other.data;
    other.data = nullptr;

    counter = other.counter;
    other.counter = nullptr;
  }

public:
  MySharedPtr() {
    data = nullptr;
    counter = nullptr;
  }

  MySharedPtr(T* data) { // NOT EXPLICIT
    this->data = data;

    if(this->data) {
      counter = new Counter();
      counter->addSharedPtr();
    }
  }

  MySharedPtr(const MySharedPtr<T>& other) {
    copyFrom(other);
  }

  MySharedPtr(MySharedPtr<T>&& other) noexcept {
    moveFrom(std::move(other));
  }

  ~MySharedPtr() {
    free();
  }

  MySharedPtr& operator=(const MySharedPtr<T>& other) {
    if(this != &other) {
      free();
      copyFrom(other);
    }

    return *this;
  }

  MySharedPtr& operator=(MySharedPtr<T>&& other) noexcept {
    if(this != &other) {
      free();
      moveFrom(std::move(other));
    }

    return *this;
  }

  const T& operator*() const {
    if(data == nullptr) {
      throw std::runtime_error("MySharedPtr: Nullptr exception!");
    }

    return *data;
  }

  T& operator*() {
    if(data == nullptr) {
      throw std::runtime_error("MySharedPtr: Nullptr exception!");
    }

    return *data;
  }

  const T* operator->() const {
    return data;
  }

  T* operator->() {
    return data;
  }

  explicit operator bool() const {
    return data;
  }

  bool isInitialized() const {
    return data != nullptr;
  }
};