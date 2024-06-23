#include "BankAccount.hh"
#include <exception>

BankAccount::BankAccount(int balance, size_t id) {
  if(balance < 0) {
    throw std::logic_error("Can't have negative balance!");
  }

  this->balance = balance;
  this->id = id;
}

BankAccount::BankAccount(size_t id) {
  this->id = id;
}

int BankAccount::getBalance() const {
  return balance;
}

void BankAccount::addMoney(int amount) {
  if(amount <= 0) {
    throw std::logic_error("Can't add 0 or negative amount of money to balance!");
  }

  balance += amount;
}

size_t BankAccount::getId() const {
  return id;
}
