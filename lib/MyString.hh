#pragma once
#include <iostream> // size_t, std::move
#include "MyVector.hh"
#define BASE 10

// MyString allows for implicit conversions using const char *
class MyString
{
  char* elems = new char[1] {'\0'};
  size_t cap = 1; // capacity of allocated memory

  void reallocate(size_t size);

  static size_t next_pow_of_2(size_t num);

  void free();
  void copyFrom(const MyString& other);
  void moveFrom(MyString&& other) noexcept;
public:
  MyString() = default;
  MyString(const MyString& other);
  MyString(MyString&& other) noexcept;
  MyString(const char *str); // NOT EXPLICIT
  explicit MyString(size_t size);
  ~MyString();

  MyString& operator=(const MyString& other);
  MyString& operator=(MyString&& other) noexcept;

  size_t length() const;
  size_t size() const;
  bool empty() const;
  size_t capacity() const;
  static size_t max_size();
  char *data();

  //size_t find(const char s);
  //size_t find(const char *s);
  //size_t find(const MyString& s);

  const char* c_str() const;

  char& operator[](size_t index);
  const char& operator[](size_t index) const;
  MyString& operator=(const char *str);
//  MyString& operator+=(char c);
//  MyString& operator+=(const char *str);
  MyString& operator+=(const MyString &other);
  bool operator==(const char *str) const;
  bool operator==(const MyString &str) const;
  friend std::ostream& operator<<(std::ostream& os, const MyString& str);
//  friend std::istream& operator>>(std::istream& is, MyString& str);
  friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

//bool operator==(const MyString& lhs, const MyString& rhs);
//bool operator!=(const MyString& lhs, const MyString& rhs);
//bool operator<(const MyString& lhs, const MyString& rhs);
//bool operator<=(const MyString& lhs, const MyString& rhs);
//bool operator>(const MyString& lhs, const MyString& rhs);
//bool operator>=(const MyString& lhs, const MyString& rhs);

int charToInt(char c);
bool isDigit(char c);
size_t stringToInt(const MyString& str, size_t start, size_t end);
void getDigits(MyVector<uint8_t>& digits, size_t num);
MyString uintToString(size_t num);
bool isLower(char c);
bool isUpper(char c);
bool isAlpha(char c);
char toLower(char c);
MyString toLower(const MyString& str);
char toUpper(char c);