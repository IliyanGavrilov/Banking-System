#include "Bank.hh"
#include <exception>

Bank::Bank(const MyString& name) {
  this->name = name;
}

void Bank::addEmployee(const BankEmployee& employee) {
  this->employees.push_back(employee);
}

void Bank::addEmployee(BankEmployee&& employee) {
  this->employees.push_back(std::move(employee));
}

void Bank::addCustomer(const std::shared_ptr<Customer>& customer) {
  this->customers.push_back(customer);
}

void Bank::receiveRequest(MyUniquePointer<Request> request) {
  if(employees.empty()) {
    throw std::logic_error("No employees to assign task to!");
  }

  // Find the least busy employee

  size_t min = employees[0].getTasksCnt();
  size_t minIdx = 0;

  for(size_t i = 0; i < employees.size(); i++) {
    if(min > employees[i].getTasksCnt()) {
      minIdx = i;
      min = employees[i].getTasksCnt();
    }
  }

  employees[minIdx].receiveTask(std::move(request));
}