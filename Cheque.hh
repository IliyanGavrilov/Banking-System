#pragma once
#include "EGN/ID.hh"

#define CODE_LEN 3

class Cheque {
  friend class ExternalEmployee;

  int cashAmount = 0; // TODO Should be a float instead of int, but isn't in examples and I need to make floatToString() func
  char code[CODE_LEN + 1] = {};
  // Must hold this otherwise the sender has to know about every customer or have
  // direct access to the banking system itself, which doesn't make sense
  ID EGN = {};

  Cheque(int cashAmount, const MyString& code, const MyString& EGN);
public:
  Cheque() = default;
  int getCashAmount() const;
  bool isValidCode(const char *code);

  const ID& getEGN() const;
};
