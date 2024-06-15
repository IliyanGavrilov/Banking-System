#pragma once
#include <iostream> // std::move

template <typename T>
class MyUniquePointer {
  T *ptr = nullptr;

  void moveFrom(MyUniquePointer&& other) {
    this->ptr = other.ptr;
    other.ptr = nullptr;
  }

  void free() {
    delete ptr;
  }

public:
  MyUniquePointer()=delete;
  MyUniquePointer(const MyUniquePointer& other) = delete;
  MyUniquePointer& operator=(const MyUniquePointer& other) = delete;

  MyUniquePointer(T* ptr) {
    this->ptr = ptr;
  }

  MyUniquePointer(MyUniquePointer&& other) noexcept {
    moveFrom(std::move(other));
  }

  MyUniquePointer& operator=(MyUniquePointer&& other) noexcept {
    if(this != &other) {
      free();
      moveFrom(std::move(other));
    }
    return *this;
  }

  ~MyUniquePointer() {
    free();
  }

  T& operator*() {
    return *ptr;
  }

  const T& operator*() const {
    return *ptr;
  }
};