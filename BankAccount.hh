#pragma once
#include <iostream> // size_t

class BankAccount {
  float balance = 0.00;
  size_t id;

public:
  explicit BankAccount(size_t id);
  BankAccount(float balance, size_t id);

  float getBalance() const;
  void addMoney(float amount);
};
