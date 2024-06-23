#pragma once
#include <iostream> // size_t
#include "../lib/MyString.hh"
#include "RequestType.hh"
#include "../Users/Customer.hh"
#include "../lib/MySharedPtr/MyWeakPtr.hh"

class Request {
  friend class InformationSystem; // To get customer
protected:
  virtual MyWeakPtr<Customer> &getCustomer() = 0;
  size_t id;
  bool _isIdSet = false;
  RequestType type; // Given by requirements, otherwise useless
  MyString details;
  MyString bankName;

  // Request isn't responsible for the sender's freeing, moving, copying, etc., because
  // the request will always have a shorter lifespan than the customer by using the Banking system correctly
  // if it is used separately from it then issues will arise so that's why I chose WeakPtr instead of a normal c ptr
  // so that there are no memory leaks even if the class is used incorrectly

public:
  Request() = delete;
  Request(RequestType type, const MySharedPtr<Customer>& customer, const MyString& bankName);
  virtual ~Request() = default;
  void description() const;
  virtual void shortDesc() const = 0;

  size_t getId() const;
  void setId(size_t id);

  bool isIdSet() const;

  RequestType getType() const;
  virtual void respond(MyString&& response) = 0;
  virtual size_t getAccountNumber() const;
};
