#pragma once
#include "User.hh"
#include "../EGN/ID.hh"
#include "../Cheque.hh"

class ExternalEmployee : public User {
public:
  ExternalEmployee(const MyString& name, const MyString& EGN, uint8_t age);
  Cheque sendCheque(int sum, const MyString& code, const MyString& egn);

  void help() const override;
  User* clone() const override;
};
