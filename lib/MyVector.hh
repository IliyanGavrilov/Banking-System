#pragma once
#include <iostream> // std::move, size_t
#include <exception>
#include <limits>

template<class T>
class MyVector {
  T* elems = nullptr;
  size_t curr = 0; // current size
  size_t cap = 0; // capacity of allocated memory

  void reallocate(size_t size) {
    this->cap = next_pow_of_2(size);
    T *temp = new T[this->cap] {};

    for(size_t i = 0; i < this->curr; i++) {
      temp[i] = std::move(elems[i]);
    }

    delete[] elems;
    this->elems = temp;
  }

  void copyElems(const T *data, size_t size) {
    for(size_t i = 0; i < size; i++) {
      this->elems[i] = data[i];
    }
  }

  static size_t next_pow_of_2(size_t num) {
    size_t pow = 1;

    while(pow < num) {
      pow *= 2;
    }

    return pow;
  }

  void free() {
    delete[] this->elems;
    this->elems = nullptr;

    this->curr = 0;
    this->cap = 0;
  }

  void copyFrom(const MyVector& other) {
    reallocate(other.curr);
    copyElems(other.elems, other.curr);

    this->curr = other.curr;
  }

  void moveFrom(MyVector&& other) noexcept {
    this->curr = other.curr;
    this->cap = other.cap;
    this->elems = other.elems;

    other.curr = 0;
    other.cap = 0;
    other.elems = nullptr;
  }

public:
  MyVector()=default;

  MyVector(const MyVector& other) {
    copyFrom(other);
  }

  MyVector(MyVector&& other) noexcept {
    moveFrom(std::move(other));
  }

  MyVector(const T *elems, size_t size) {
    if(!elems) {
      throw std::invalid_argument("Nullptr exception, creating vector!");
    }

    reallocate(size);
    copyElems(elems, size);

    this->curr = size;
  }

  explicit MyVector(size_t size) {
    reallocate(size);
    this->curr = size;
  }

  ~MyVector() {
    free();
  }

  MyVector& operator=(const MyVector& other) {
    if(this != &other) {
      free();
      copyFrom(other);
    }

    return *this;
  }

  MyVector& operator=(MyVector&& other) noexcept {
    if(this != &other) {
      free();
      moveFrom(std::move(other));
    }

    return *this;
  }

  // Size methods
  size_t size() const {
    return curr;
  }

  size_t capacity() const {
    return cap;
  }

  bool empty() const {
    return (this->curr == 0);
  }

  static size_t max_size() {
    return std::numeric_limits<size_t>::max();
  }

//  void resize(size_t size) {
//    if(curr < size) {
//      for(size_t i = 0; i < size - curr; i++) {
//        this->push_back(T());
//      }
//    }
//
//    curr = size;
//  }

  // Element access
//  T& at(size_t index) const {
//    if(index >= curr) {
//      throw std::out_of_range("MyVector::at(): Reading out of range!");
//    }
//
//    return this->elems[index];
//  }

//  T& front() const {
//    return this->elems[0];
//  }
//
//  T& back() const {
//    return this->elems[this->curr - 1];
//  }

  T *data() {
    return this->elems;
  }

  const T& operator[](size_t index) const {
    if(index >= curr) {
      throw std::out_of_range("MyVector::operator[] const: Reading out of range!");
    }

    return this->elems[index];
  }

  bool contains(const T &elem) const {
    for(size_t i = 0; i < curr; i++) {
      if(elem == elems[i]) {
        return true;
      }
    }

    return false;
  }

  // Modifiers
  void push_back(T&& elem) {
    insert(this->curr, std::move(elem));
  }

  void push_back(const T& elem) {
    insert(this->curr, elem);
  }

  void pop_back() {
    if(this->curr == 0) {
      throw std::out_of_range("MyVector::pop_back(): Vector is empty!");
    }

    this->curr--;
  }

  void insert(size_t index, T &&elem) {
    if(index > this->curr) {
      throw std::out_of_range("MyVector::move_insert(): Invalid index!");
    }

    if(this->curr >= this->cap) {
      reallocate(curr + 1);
    }

    for(int i = this->curr - 1; i >= (int) index; i--) {
      this->elems[i + 1] = this->elems[i];
    }

    this->elems[index] = std::move(elem);
    this->curr++;
  }

  void insert(size_t index, const T &elem) {
    if(index > this->curr) {
      throw std::out_of_range("MyVector::copy_insert(): Invalid index!");
    }

    if(this->curr >= this->cap) {
      reallocate(curr + 1);
    }

    for(int i = this->curr - 1; i >= (int) index; i--) {
      this->elems[i + 1] = this->elems[i];
    }

    this->elems[index] = elem;
    this->curr++;
  }

//  void clear() {
//    free();
//  }

  T& operator[](size_t index) {
    if(index >= this->curr) {
      throw std::out_of_range("MyVector::operator[]: Writing out of range!");
    }

    return this->elems[index];
  }

  friend std::ostream& operator<<(std::ostream& o, const MyVector& v)
  {
    o << "{";
    for(size_t i = 0; i < v.curr; i++) {
      if(i != 0) {
        o << ", ";
      }
      o << v.elems[i];
    }
    o << "}";

    return o;
  }
};

//template<class T>
//bool operator==(const MyVector<T>& lhs, const MyVector<T>& rhs) {
//  if(lhs.getSize() != rhs.getSize()) {
//    return false;
//  }
//
//  for(size_t i = 0; i < lhs.getSize(); i++) {
//    if(lhs.at(i) != rhs.at(i)) {
//      return false;
//    }
//  }
//
//  return true;
//}
//
//template<class T>
//bool operator!=(const MyVector<T>& lhs, const MyVector<T>& rhs) {
//  return !(lhs == rhs);
//}
//
//template<class T>
//void swap(MyVector<T>& lhs, MyVector<T>& rhs) {
//  MyVector<T> temp(lhs);
//  lhs = rhs;
//  rhs = temp;
//}