#pragma once
#include <iostream> // size_t

class BankAccount {
  int balance = 0; // Should be a float instead of int, but isn't in examples and I need to make floatToString() func
  size_t id = 0;

public:
  BankAccount() = default;
  explicit BankAccount(size_t id);
  BankAccount(int balance, size_t id);

  int getBalance() const;
  size_t getId() const;

  void addMoney(int amount);
};
