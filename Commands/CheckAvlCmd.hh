#pragma once
#include "Command.hh"
//typedef int(Customer::*fptr)(const MyString &bankName, size_t account_number) const;

class CheckAvlCmd : public Command {
public:
  void execute(const MyVector<MyString>& args) const final;
};
