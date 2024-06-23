#include "CloseRequest.hh"

MyWeakPtr<Customer> &CloseRequest::getCustomer() {
  return customer;
}

CloseRequest::CloseRequest(const MySharedPtr<Customer>& customer,
                           size_t accountNumber, const MyString& bankName) : Request(RequestType::CLOSE, customer, bankName) {

  this->details += ("Bank: " + bankName + "\nAccount number: " + MyString(uintToString(accountNumber)) +
                   "\nBalance: " + MyString(uintToString(customer->checkBalance(bankName, accountNumber))));
  this->accountNumber = accountNumber;
  // Because the constructor of weak_ptr takes a non-const shared_ptr
  this->customer = const_cast<MySharedPtr<Customer>&>(customer);
}

void CloseRequest::shortDesc() const {
  std::cout << "[" << id << "]" << getRequestName(type) << " - " << customer.lock()->getName() <<
  " wants to close account with id " << accountNumber << ".\n";
}

void CloseRequest::respond(MyString&& response) {
  customer.lock()->receiveMail(std::move(response));
}

size_t CloseRequest::getAccountNumber() const {
  return accountNumber;
}
