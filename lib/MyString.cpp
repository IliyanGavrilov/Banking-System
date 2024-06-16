#include "MyString.hh"
#include <cstring> // For strlen, strcpy, strcmp, etc.
#include <limits>

void MyString::reallocate(size_t size) {
  this->cap = next_pow_of_2(size);
  char *temp = new char[this->cap] {'\0'};

  strcpy(temp, elems);

  delete[] elems;
  this->elems = temp;
}

size_t MyString::next_pow_of_2(size_t num) {
  size_t pow = 1;

  while(pow < num) {
    pow *= 2;
  }

  return pow;
}

void MyString::free() {
  this->cap = 0;
  delete[] this->elems;
  this->elems = nullptr;
}

void MyString::copyFrom(const MyString& other) {
  reallocate(strlen(other.elems) + 1);
  strcpy(elems, other.elems);
}

void MyString::moveFrom(MyString&& other) noexcept {
  this->cap = other.cap;
  this->elems = other.elems;

  other.cap = 0;
  other.elems = nullptr;
}

MyString::MyString(const MyString& other) {
  copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept {
  moveFrom(std::move(other));
}

MyString::MyString(const char *str) {
  if(!str) {
    throw std::invalid_argument("Nullptr exception, creating string!");
  }

  reallocate(strlen(str) + 1);
  strcpy(elems, str);
}

MyString::MyString(size_t size) {
  reallocate(size + 1);
}

MyString::~MyString() {
  free();
}

MyString& MyString::operator=(const MyString& other) {
  if(this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
  if(this != &other) {
    free();
    moveFrom(std::move(other));
  }

  return *this;
}

size_t MyString::length() const {
  return strlen(elems);
}

size_t MyString::size() const {
  return strlen(elems);
}

bool MyString::empty() const {
  return strlen(elems) == 0;
}

const char* MyString::c_str() const {
  return this->elems;
}

size_t MyString::capacity() const {
  return cap;
}

size_t MyString::max_size() {
  return std::numeric_limits<size_t>::max();
}

char *MyString::data() {
  return this->elems;
}

const char& MyString::operator[](size_t index) const {
  if(index >= strlen(elems)) {
    throw std::out_of_range("MyString::operator[] const: Reading out of range!");
  }

  return this->elems[index];
}

char& MyString::operator[](size_t index) {
  if(index >= length()) {
    throw std::out_of_range("MyString::operator[] const: Reading out of range!");
  }

  return elems[index];
}

MyString& MyString::operator=(const char *str) {
  return this->operator=(MyString(str));
}

bool MyString::operator==(const char *str) const {
  return (strcmp(elems, str) == 0);
}

bool MyString::operator==(const MyString &s) const {
  return (strcmp(elems, s.elems) == 0);
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
  os << str.elems;

  return os;
}

//std::istream& operator>>(std::istream& is, MyString& str) {
//
//}







//MyString& MyString::operator+=(char c) {
//  if(length() + 1 >)
//}
//
//MyString& MyString::operator+=(const char *str) {
//  return this->operator+=(MyString(str));
//}
//
//MyString& MyString::operator+=(const MyString &other) {
//    if(length() + other.length() > cap) {
//      cap = next_pow_of_2(length() + other.length() + 1);
//      reallocate(strlen(elems) + 1);
//    }
//
//    size_t curr = strlen(elems) + 1;
//    size_t other_curr = strlen(other.elems) + 1;
//
//    for(size_t i = curr; i <= curr + other_curr; i++) {
//      elems[i] = other.elems[i - curr];
//    }
//}
//
//MyString operator+(const MyString& lhs, const MyString& rhs) {
//  MyString result(lhs.length() + rhs.length());
//
//  result += lhs;
//  result += rhs;
//
//  return result;
//}

int charToInt(char c) {
  if(c >= '0' && c <= '9') {
    return c & 0xF;
  }

  return -1;
}

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

size_t stringToInt(const MyString& str, size_t start, size_t end) {
  size_t num = 0;

  for(size_t i = start; i < end; i++) {
    if(isDigit(str[i])) {
      num *= 10;
      num += charToInt(str[i]);
    }
  }

  return num;
}

bool isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}