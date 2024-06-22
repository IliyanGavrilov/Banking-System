#pragma once
#include "EGN/ID.hh"

#define CODE_LEN 3

class Cheque {
  friend class ExternalEmployee;

  float cashAmount;
  char code[CODE_LEN + 1];
  // Must hold this otherwise the sender has to know about every customer or have
  // direct access to the banking system itself, which doesn't make sense
  ID EGN;

  Cheque(float cashAmount, const MyString& code, const MyString& EGN);
  Cheque(float cashAmount, const MyString& code, const ID& EGN);

public:
  Cheque() = delete;

  float getCashAmount() const;
  bool isValidCode(const char *code);

  const ID& getEGN() const;
};
