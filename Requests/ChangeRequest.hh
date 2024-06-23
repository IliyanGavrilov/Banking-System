#pragma once
#include "Request.hh"

class ChangeRequest : public Request {
  MyWeakPtr<Customer> customer;
  //std::shared_ptr<Bank> toBank;
  MyString toBankName;
  size_t accountNumber;

  MyWeakPtr<Customer> &getCustomer() override;
public:
  ChangeRequest() = delete;
  ChangeRequest(const MySharedPtr<Customer>& customer, size_t accountNumber, const MyString& currBankName, const MyString& newBankName);

  void shortDesc() const override;
  void respond(MyString&& response) override;

  size_t getAccountNumber() const override;
};
