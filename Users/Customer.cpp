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
  User::help();
  std::cout << "check_avl [bank_name] [account_number] - Check balance for given account.\n";
  std::cout << "open [bank_name] - Send request to open new account in given bank.\n";
  std::cout << "close [bank_name] [account_number] - Send request to close given account in bank.\n";
  std::cout << "redeem [bank_name] [account_number] [verification_code] - Redeem cheque in your name.\n";
  std::cout << "change [new_bank_name] [current_bank_name] [account_number] - " <<
               "Send request to move given account from one bank to another.\n";
  std::cout << "list [bank_name] - Lists all your accounts in a given bank.\n";
  std::cout << "messages - Shows all received messages in chronological order.\n";
}

void Customer::whoami() const {
  User::whoami();
  std::cout << "(Customer)!\n";
}