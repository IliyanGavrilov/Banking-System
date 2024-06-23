#pragma once
#include "Request.hh"

class ChangeRequest : public Request {
  MyString fromBank; // Change from
  //std::shared_ptr<Bank> toBank;
public:
  ChangeRequest() = delete;
  ChangeRequest(const MySharedPtr<Customer>& customer, const MyString& bank);

  void shortDesc() const override;
};
