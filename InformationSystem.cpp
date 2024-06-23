#include "InformationSystem.hh"
#include "Bank.hh"
#include "Requests/Request.hh"
#include <ctime>
#include <exception>

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

void InformationSystem::addBank(const MyString& bankName) {
  banks.push_back(new Bank(bankName));
}

void InformationSystem::addUser(const MySharedPtr<User>& user, const MyString& associatedBankName) {
  if(!associatedBankName.empty()) {

  }
  else {
    users.push_back(user);
  }
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
    // I didn't have time to finish this but in change request the system should notify one bank and then the other
    // (the BankEmployees do that themselves the system just transfers the requests, via the receiveRequest system)
    // and when the request is approved then it deletes the account from the old bank and creates it in the new bank
    // If it's not approved nothing happens.
  }

  request->getCustomer().lock()->receiveMail(msg);
}

MySharedPtr<User> &InformationSystem::getUser(const MyString& name) {
  for(size_t i = 0; i < users.size(); i++) {
    if(users[i]->getName() == name) {
      return users[i];
    }
  }
  throw std::logic_error("Bank with such name doesn't exist!");
}

MyUniquePointer<Bank> & InformationSystem::getBank(const MyString& associatedBankName) {
  for(size_t i = 0; i < banks.size(); i++) {
    if(banks[i]->getName() == associatedBankName) {
      return banks[i];
    }
  }
  throw std::logic_error("Bank with such name doesn't exist!");
}

void InformationSystem::redeemCheque(const ID& EGN, const MyString &bankName, size_t accountNumber, const MyString &verification_code) {
  for(size_t i = 0; i < notRedeemedCheques.size(); i++) {
    if(notRedeemedCheques[i]->getEGN() == EGN) {
//      if(notRedeemedCheques[i]->isValidCode(verification_code)) {
//        // redeem TODO
//      }
//      else {
//       // throw std:: not found cheque;
//      }
    }
  }
}
