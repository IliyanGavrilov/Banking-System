#pragma once
#include <iostream> // std::move

template <class T>
class MyUniquePointer {
  T *data = nullptr;

  void free() {
    delete data;
  }

  void moveFrom(MyUniquePointer&& other) noexcept {
    this->data = other.data;
    other.data = nullptr;
  }

public:
  MyUniquePointer() = default;
  MyUniquePointer(const MyUniquePointer& other) = delete;
  MyUniquePointer& operator=(const MyUniquePointer& other) = delete;

  MyUniquePointer(T* data) { // NOT EXPLICIT
    this->data = data;
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
    if(data == nullptr) {
      throw std::runtime_error("MySharedPtr: Nullptr exception!");
    }

    return *data;
  }

  const T& operator*() const {
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