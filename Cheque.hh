#pragma once
#define CODE_LEN 3

class Cheque {
  float cashAmount = 0.0;
  char code[CODE_LEN] = {};

public:
  Cheque()=delete;
  Cheque(float cashAmount, char *code);

  float getCashAmount() const;
  bool isValidCode(char *code);
};
