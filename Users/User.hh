#pragma once
#include "../lib/MyString.hh"
#include "../lib/MyVector.hh"
#include "../EGN/ID.hh"
#include "../Cheque.hh"
#include "../Messages.hh"

class User {
protected:
  MyString name = "Ivan";
  ID EGN = {};
  uint8_t age = 0;

public:
  // Some default state, so we can put it in a vector
  User() = default;
  User(const MyString& name, const ID& EGN, uint8_t age);
  virtual ~User() = default;

  const MyString &getName() const;

  void whoami();
  virtual void help() const = 0;
  virtual User* clone() const = 0;
};
