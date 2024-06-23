#include "OpenRequest.hh"

MyWeakPtr<Customer> &OpenRequest::getCustomer() {
  return customer;
}

OpenRequest::OpenRequest(const MySharedPtr<Customer>& customer,
                         const MyString& bankName) : Request(RequestType::OPEN, customer, bankName) {
  // Because the constructor of weak_ptr takes a non-const shared_ptr
  this->customer = const_cast<MySharedPtr<Customer>&>(customer);
}

void OpenRequest::shortDesc() const {
  std::cout << "[" << id << "]" << getRequestName(type) << " - " << customer.lock()->getName() << " wants to create an account.\n";
}

void OpenRequest::respond(MyString&& response) {
  customer.lock()->receiveMail(std::move(response));
}
