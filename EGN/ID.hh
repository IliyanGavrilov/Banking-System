#pragma once
#include "../lib/MyString.hh"
#include "IDRegion.hh"
#define EGN_LEN 10
#define MOD 11 // The checkSum number is reduced to mod11 (module 11)

class ID {
  MyString EGN = "0001010000"; // Default valid EGN
  IDRegion region = IDRegion::Blagoevgrad;
public:
  ID()=default;
  explicit ID(const MyString& str);

  const MyString &getEGN() const;
  void setEGN(const MyString &str);
  void validateEGN(const MyString &str) const;

  // How many people (of same gender) born on the same day in the same region before this person
  size_t peopleBornBefore();

  // Is girl or boy
  bool isBoy() const;
  bool isGirl() const;
};

int charToInt(char c);
bool isDigit(char c);
size_t stringToInt(const MyString& str, size_t start, size_t end);