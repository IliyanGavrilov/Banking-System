#include "BankAccount.hh"
#include <exception>

BankAccount::BankAccount(float balance, size_t id) {
  if(balance < 0) {
    throw std::logic_error("Can't have negative balance!");
  }

  this->balance = balance;
  this->id = id;
}

BankAccount::BankAccount(size_t id) {
  this->id = id;
}

float BankAccount::getBalance() const {
  return balance;
}

void BankAccount::addMoney(float amount) {
  if(amount <= 0) {
    throw std::logic_error("Can't add 0 or negative amount of money to balance!");
  }

  balance += amount;
}