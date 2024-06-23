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
  // BIG 6, no copying because of BankEmployee
  Bank() = default; // So it can be in vector
  Bank(const Bank& other) = delete;
  Bank(Bank&& other) = default;
  Bank& operator=(const Bank& other) = delete;
  Bank& operator=(Bank&& other) = default;
  ~Bank() = default;

  explicit Bank(const MyString& name);

  const MyString &getName() const;

  void addEmployee(BankEmployee&& employee);
  void addCustomer(const MySharedPtr<Customer>& customer); // [[maybe_unused]]
  void receiveRequest(MyUniquePointer<Request>&& request);
};
