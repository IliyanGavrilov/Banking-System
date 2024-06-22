#pragma once
#include "lib/MyVector.hh"
#include "lib/MyUniquePointer.hh"
#include "Users/BankEmployee.hh"
#include "Requests/Request.hh"
#include "BankAccount.hh"

class Bank {
  MyString name;
  MyVector<BankEmployee> employees = {};

protected:
  MyVector<std::shared_ptr<Customer>> customers = {}; // Hold customers so we can verify close and change requests

public:
  explicit Bank(const MyString& name);
  void addEmployee(const BankEmployee& employee);
  void addEmployee(BankEmployee&& employee);
  void addCustomer(const std::shared_ptr<Customer>& customer);
  void receiveRequest(MyUniquePointer<Request> request);
};
