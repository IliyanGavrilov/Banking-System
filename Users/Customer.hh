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

  static size_t counter;
  // Should be probably be a map (with key bank) of maps (with key accountNum) of BankAccounts for faster accessing
  // instead of searching every time
  MyVector<MyPair<MyString, BankAccount>> accounts;
  MyVector<Cheque> redeemedCheques = {}; // TODO address and record of redeemed cheques????
  Messages mail;
  MySharedPtr<InformationSystem> system;
public:
  int checkBalance(const MyString& bankName, size_t accountNumber) const; // check_avl
  void open(const MyString& bankName); // open

//  void close(const MyString& bankName, size_t accountNumber) const;
//  void redeem(const MyString& bankName, size_t accountNumber, const MyString& verification_code) const;
//  void change(const MyString& newBankName, const MyString& currBankName, size_t accountNumber) const;
//  void list(const MyString& bankName) const;
//  void messages() const;

  void addAccount(const MyString& bankName, const BankAccount& acc);
  void receiveMail(MyString&& message);
  void receiveMail(const MyString& message);
  MyString toString() const; // Different from "whoami" judging by the examples

  void help() const override;
  User* clone() const override;
};
