#pragma once
#include "lib/MyString.hh"
#define EGN_LEN 10

class IdentificationNumber {
  MyString EGN = "0001010000"; // Default valid EGN
public:
  IdentificationNumber()=default;
  explicit IdentificationNumber(const MyString& str);

  const MyString &getEGN() const;
  void setEGN(const MyString &str);
  void validateEGN(const MyString &str);
};

int charToInt(char c);
bool isDigit(char c);