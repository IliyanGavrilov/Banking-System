#include "Request.hh"
#include <exception>

Request::Request(RequestType type, const MySharedPtr<Customer>& customer, const MyString& bankName) {
  id = 0;

  this->type = type;
  this->details = customer->toString();
  this->bankName = bankName;
}

void Request::description() const {
  std::cout << getRequestName(type) << " request from:\n";
  std::cout << details << "\n";
}

RequestType Request::getType() const {
  return type;
}

size_t Request::getId() const {
  if(!_isIdSet) {
    throw std::logic_error("Id not set!");
  }

  return id;
}

void Request::setId(size_t id) {
  this->id = id;
  _isIdSet = true;
}

bool Request::isIdSet() const {
  return _isIdSet;
}

size_t Request::getAccountNumber() const {
  if(type != RequestType::CLOSE) {
    throw std::logic_error("Not a close request!");
  }

  return 0;
}