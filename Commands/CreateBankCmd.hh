#pragma once
#include "Command.hh"
//typedef void(CommandInterface::*fptr)(const MyString &bankName);

class CreateBankCmd : public Command {
//  fptr funcPtr = &CommandInterface::createBank;
public:
  void execute(const MyVector<MyString>& args) const final;
};
