#pragma once
#include "../Users/User.hh"
#include "CommandInterface.hh"

class Command {
public:
  virtual ~Command() = default;
  virtual void execute(const MyVector<MyString>& args) const = 0;
};
