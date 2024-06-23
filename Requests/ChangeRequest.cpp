#include "ChangeRequest.hh"

ChangeRequest::ChangeRequest(const MySharedPtr<Customer>& customer, size_t accountNumber, const MyString& currBankName, const MyString& newBankName) :
        Request(RequestType::CHANGE1, customer, currBankName) {
  //this->details += ;
  this->accountNumber = accountNumber;
  // Because the constructor of weak_ptr takes a non-const shared_ptr
  this->toBankName = newBankName;
  this->customer = const_cast<MySharedPtr<Customer>&>(customer);
}

void ChangeRequest::shortDesc() const {
}

MyWeakPtr<Customer> &ChangeRequest::getCustomer() {
  return customer;
}

void ChangeRequest::respond(MyString &&response) {
  customer.lock()->receiveMail(std::move(response));
}

size_t ChangeRequest::getAccountNumber() const {
  return accountNumber;
}
