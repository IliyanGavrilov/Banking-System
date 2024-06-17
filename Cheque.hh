#pragma once
#include "/EGN/ID.hh"
#include "EGN/ID.hh"

#define CODE_LEN 3

class Cheque {
  float cashAmount;
  char code[CODE_LEN + 1];
  // Must hold this otherwise the sender has to know about every customer or have
  // direct access to the banking system itself, which doesn't make sense
  ID EGN;

public:
  Cheque() = delete;
  Cheque(float cashAmount, const MyString& code, const MyString& EGN);
  Cheque(float cashAmount, const MyString& code, const ID& EGN);

  float getCashAmount() const;
  bool isValidCode(char *code);

  const ID& getEGN() const;
};
