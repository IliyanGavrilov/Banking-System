#pragma once
#include <iostream> // std::move

template <class T, class U>
class MyPair {
  T _first {};
  U _second {};

public:
  MyPair() = default;
  MyPair(const T& first, const U& second) : _first(first), _second(second) {}
  MyPair(T&& first, U&& second) : _first(std::move(first)), _second(std::move(second)) {}


  const T& first() const {
    return _first;
  }

  const U& second() const {
    return _second;
  }

  T& operator=(const T& first) {
    _first = first;

    return _first;
  }

  T& operator=(T&& first) {
    _first = std::move(first);

    return _first;
  }

  U& operator=(const U& second) {
    _second = second;

    return _second;
  }

  U& operator=(U&& second) {
    _second = std::move(second);

    return _second;
  }
};