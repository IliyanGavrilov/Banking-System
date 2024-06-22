#include "Cheque.hh"
#include "lib/MyString.hh"
#include <cstring>

Cheque::Cheque(float cashAmount, const MyString& code, const ID &EGN) : EGN(EGN) {
  if(cashAmount <= 0) {
    throw std::out_of_range("Cheque can't have 0 or negative amount of cash in it!");
  }

  if(code.length() != CODE_LEN) {
    throw std::out_of_range("Cheque validation code must be 3 symbols long!");
  }

  for(size_t i = 0; i < CODE_LEN; i++) {
    if(!isDigit(code[i]) && !isAlpha(code[i])) {
      throw std::invalid_argument("Invalid characters found in cheque validation code! Must contain only letters and numbers!");
    }
  }

  strcpy(this->code, code.c_str());
  this->cashAmount = cashAmount;
}

Cheque::Cheque(float cashAmount, const MyString& code, const MyString& EGN) : Cheque(cashAmount, code, ID(EGN)) {}

float Cheque::getCashAmount() const {
  return cashAmount;
}

bool Cheque::isValidCode(const char *code) {
  return !strcmp(this->code, code);
}

const ID& Cheque::getEGN() const {
  return EGN;
}
