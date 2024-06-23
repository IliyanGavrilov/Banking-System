#include "Customer.hh"
#include <exception>
#include "../Requests/OpenRequest.hh"
#include "../Requests/CloseRequest.hh"

size_t Customer::counter = 0;

int Customer::checkBalance(const MyString& bankName, size_t accountNumber) const {
  for(size_t i = 0; i < accounts.size(); i++) {
    if(accounts[i].first() == bankName && accounts[i].second().getId() == accountNumber) {
      return accounts[i].second().getBalance();
    }
  }

  throw std::invalid_argument("No such account exists!");
}

void Customer::open(const MyString& bankName) {
  system->receiveRequest(new OpenRequest(this, bankName), bankName);
}

void Customer::addAccount(const MyString& bankName, const BankAccount& acc) {
  accounts.push_back(MyPair<MyString, BankAccount>(bankName, acc));
}

void Customer::receiveMail(MyString&& message) {
  mail.receive(std::move(message));
}

void Customer::receiveMail(const MyString& message) {
  mail.receive(message);
}

MyString Customer::toString() const {
  return MyString("Name: ") + name + MyString("\n") +
         MyString("EGN: ") + EGN.getEGN() + MyString("\n") +
         MyString("Age: ") + MyString(uintToString(age)) + MyString("\n") ;
}

void Customer::help() const {

}
