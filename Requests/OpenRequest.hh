#pragma once
#include "Request.hh"

class OpenRequest : public Request {
  MyWeakPtr<Customer> customer;

  MyWeakPtr<Customer> &getCustomer() override;
public:
  OpenRequest() = delete;
  OpenRequest(const MySharedPtr<Customer>& customer, const MyString& bankName);

  void shortDesc() const override;
  void respond(MyString&& response) override;
};
