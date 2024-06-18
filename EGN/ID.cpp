#include "ID.hh"
#include "../lib/MyString.hh"

ID::ID(const MyString& str) {
  setEGN(str);
}

void ID::setEGN(const MyString &str) {
  validateEGN(str);
  region = getRegion(stringToInt(str, EGN_LEN - 4, EGN_LEN));
  EGN = str;
}

void ID::validateEGN(const MyString& str) const {
  // Check length
  if(str.length() != EGN_LEN) {
    throw std::out_of_range("EGN length is not 10 digits long!");
  }

  // Check if all digits
  for(int i = 0; i < EGN_LEN; i++) {
    if(isDigit(str[i])) {
      throw std::invalid_argument("EGN contains non-digit symbols!");
    }
  }

  // Check if valid date TODO

  // CheckSum verification
  // These special multipliers come from other special numbers M : 0 0 0 1 2 5 11 23 46
  // And the multiplier formula is T = 2^P - M * 11, where P is the current position starting from 1 (all the way to 9)
  int specialMultipliers[] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
  size_t checkSum = 0;

  for(size_t i = 0; i < EGN_LEN - 1; i++) {
    checkSum += charToInt(str[i]) * specialMultipliers[i];
  }

  checkSum -= checkSum/MOD * MOD;

  if(str[EGN_LEN - 1] != checkSum) {
    throw std::invalid_argument ("EGN checkSum verification failed!");
  }
}

size_t ID::peopleBornBefore() {
  size_t diff = stringToInt(EGN, EGN_LEN - 4, EGN_LEN) - (int) region;

  return diff/2; // rounded down
}

bool ID::isBoy() const {
  // If penultimate number is even it's a boy, otherwise it's a girl
  return (charToInt(EGN[EGN_LEN - 2]) % 2 == 0);
}

bool ID::isGirl() const {
  return !isBoy();
}

bool operator==(const ID& id1, const ID& id2) {
  return id1.EGN == id2.EGN;
}