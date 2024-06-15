#include "IdentificationNumber.hh"
#include <cstring>

IdentificationNumber::IdentificationNumber(const MyString& str) {
  setEGN(str);
}

const MyString &IdentificationNumber::getEGN() const {
  return EGN;
}

void IdentificationNumber::setEGN(const MyString &str) {
  validateEGN(str);

  EGN = str;
}

void IdentificationNumber::validateEGN(const MyString& str) {
  // Check length
  if(EGN.length() != EGN_LEN) {
    throw std::out_of_range("EGN length is not 10 digits long!");
  }

  // Check if all digits
  for(int i = 0; i < EGN_LEN; i++) {
    if(isDigit(EGN[i])) {
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
    checkSum += charToInt(EGN[i]) * specialMultipliers[i];
  }

  checkSum -= checkSum/11 * 11;

  if(EGN[EGN_LEN - 1] != checkSum) {
    throw std::invalid_argument ("EGN checkSum verification failed!");
  }
}

int charToInt(char c) {
  if(c >= '0' && c <= '9') {
    return c & 0xF;
  }

  return -1;
}

bool isDigit(char c) {
  if(c >= '0' && c <= '9') {
    return true;
  }

  return false;
}