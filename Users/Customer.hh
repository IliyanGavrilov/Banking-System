#pragma once
#include "User.hh"
#include "../lib/MyVector.hh"
#include "../lib/MyString.hh"
#include "../Messages.hh"
#include "../BankAccount.hh"
#include "../lib/MyPair.hh"
#include "../InformationSystem.hh"
#include "../lib/MySharedPtr/MyWeakPtr.hh"

class Customer : public User {
  friend class InformationSystem;
  static MyVector<MyPair<const MyString, MyUniquePointer<Command>>> commands;
  // Should be probably be a map (with key bank) of maps (with key accountNum) of BankAccounts for faster accessing
  // instead of searching every time
  MyVector<MyPair<MyString, BankAccount>> accounts;
  MyVector<Cheque> redeemedCheques = {}; // TODO address and record of redeemed cheques????
  Messages mail = {};
  MySharedPtr<InformationSystem> system = InformationSystem::getInstance();
public:
  Customer(const MyString& name, const MyString& EGN, uint8_t age);

  int checkBalance(const MyString& bankName, size_t accountNumber) const; // check_avl
  void open(const MyString& bankName); // open
  void close(const MyString& bankName, size_t accountNumber);
  void redeem(const MyString& bankName, size_t accountNumber, const MyString& verification_code);
  void change(const MyString& newBankName, const MyString& currBankName, size_t accountNumber);
  void list(const MyString& bankName) const;
  void messages() const;

  void addAccount(const MyString& bankName, const BankAccount& acc);
  void receiveMail(MyString&& message);
  void receiveMail(const MyString& message);
  MyString toString() const; // Different from "whoami" judging by the examples

  void help() const override;
  void whoami() const override;
  MyUniquePointer<Command> getCommand(const MyString& cmdName) const override;
};
