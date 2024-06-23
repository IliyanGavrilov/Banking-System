#include "InformationSystem.hh"
#include "Bank.hh"
#include "Requests/Request.hh"
#include <ctime>

InformationSystem* InformationSystem::instance = nullptr;

InformationSystem* InformationSystem::getInstance() {
  if (!instance) {
    instance = new InformationSystem();
  }
  return instance;
}

void InformationSystem::addBank(MyUniquePointer<Bank>&& bank) {
  banks.push_back(std::move(bank));
}

void InformationSystem::addUser(const MySharedPtr<User>& user) {
  users.push_back(user);
}

void InformationSystem::receiveRequest(MyUniquePointer<Request> &&request, const MyString& receiver) {
  for(size_t i = 0; i < banks.size(); i++) {
    if(receiver == (*banks[i]).getName()) {
      (*banks[i]).receiveRequest(std::move(request));
    }
  }
  throw std::invalid_argument("Request not sent! No such bank exists!");
}

void InformationSystem::executeRequest(MyUniquePointer<Request>&& request) {
  MyString msg;

  if(request->getType() == RequestType::OPEN) {
    size_t accNum = rand();

    // Other way is to have operator== for users and to find the exact user in the vector of users
    request->getCustomer().lock()->addAccount(request->bankName, BankAccount(accNum));
    msg = "You opened an account in " + request->bankName + "! Your account id is " + uintToString(accNum);
  }
  else if(request->getType() == RequestType::CLOSE) {

    for (size_t i = 0; i < request->getCustomer().lock()->accounts.size(); i++) {
      if (request->getCustomer().lock()->accounts[i].first() == request->bankName &&
          request->getCustomer().lock()->accounts[i].second().getId() == request->getAccountNumber()) {
        request->getCustomer().lock()->accounts.pop(i);
      }
    }

  }
  else {
    // TODO
  }

  request->getCustomer().lock()->receiveMail(msg);
}