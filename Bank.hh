#pragma once
#include "lib/MyVector.hh"
#include "lib/MyUniquePointer.hh"
#include "Users/BankEmployee.hh"
#include "Users/Customer.hh"
#include "Requests/Request.hh"
#include "BankAccount.hh"

class Bank {
  MyString name;
  MyVector<BankEmployee> employees = {};
  MyVector<MySharedPtr<Customer>> customers = {}; // Hold customers so we can verify close and change requests

public:
  explicit Bank(const MyString& name);

  const MyString &getName() const;

  void addEmployee(BankEmployee&& employee);
  void addCustomer(const MySharedPtr<Customer>& customer);
  void receiveRequest(MyUniquePointer<Request>&& request);
};
