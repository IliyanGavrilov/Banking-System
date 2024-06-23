#pragma once
#include "Request.hh"

class CloseRequest : public Request {
  MyWeakPtr<Customer> customer;
  size_t accountNumber;

  MyWeakPtr<Customer> &getCustomer() override;
public:
  CloseRequest() = delete;
  CloseRequest(const MySharedPtr<Customer>& customer, size_t accountNumber, const MyString& bankName);

  void shortDesc() const override;
  void respond(MyString&& response) override;

  size_t getAccountNumber() const override;
};
