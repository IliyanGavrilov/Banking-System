#include "Cheque.hh"
#include "lib/MyString.hh"
#include <cstring>

Cheque::Cheque(float cashAmount, char *code) {
  if(cashAmount <= 0) {
    throw std::out_of_range("Cheque can't have 0 or negative amount of cash in it!");
  }

  if(strlen(code) != CODE_LEN) {
    throw std::out_of_range("Cheque validation code must be 3 symbols long!");
  }

  for(size_t i = 0; i < CODE_LEN; i++) {
    if(!is_digit(code[i]) && !is_alpha(code[i])) {
      throw std::invalid_argument("Invalid characters found in cheque validation code! Must contain only letters and numbers!");
    }
  }

  strcpy(this->code, code);
  this->cashAmount = cashAmount;
}

float Cheque::getCashAmount() const {
  return cashAmount;
}

bool Cheque::isValidCode(char *code) {
  return !strcmp(this->code, code);
}
