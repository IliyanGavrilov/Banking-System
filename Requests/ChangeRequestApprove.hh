#pragma once
#include "Request.hh"
#include "../Users/BankEmployee.hh"

class ChangeRequestApprove : public Request {
  size_t accountNumber;
  int balance;
  MySharedPtr<BankEmployee> employee;
public:
  ChangeRequestApprove() = delete;
  void shortDesc() const override;
};
