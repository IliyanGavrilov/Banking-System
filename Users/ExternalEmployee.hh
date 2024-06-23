#pragma once
#include "User.hh"
#include "../EGN/ID.hh"
#include "../Cheque.hh"
#include "../lib/MyPair.hh"

class ExternalEmployee : public User {
  static MyVector<MyPair<const MyString, MyUniquePointer<Command>>> commands;
public:
  ExternalEmployee(const MyString& name, const MyString& EGN, uint8_t age);
  Cheque sendCheque(int sum, const MyString& code, const MyString& egn);

  void help() const override;
  void whoami() const override;
  MyUniquePointer<Command> getCommand(const MyString& cmdName) const override;
};
