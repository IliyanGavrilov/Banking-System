#pragma once
#include "Users/User.hh"
#include "lib/MyVector.hh"
#include "lib/MyUniquePointer.hh"
#include "lib/MySharedPtr/MyWeakPtr.hh"

class Request;
class Bank;

// Something like a website/the Internet itself, providing a network connection between banks and users
class InformationSystem {
  MyVector<MyUniquePointer<Bank>> banks = {};
  MyVector<MySharedPtr<User>> users = {}; // Heterogeneous container

public:
  InformationSystem() = default;

  void addBank(const Bank& bank);
  void addUser(const User& user);
  void addBank(MyUniquePointer<Bank>&& bank);
  void addUser(const MySharedPtr<User>& user);

  void receiveRequest(MyUniquePointer<Request>&& request, const MyString& receiver);
  void executeRequest(MyUniquePointer<Request>&& request);
};
