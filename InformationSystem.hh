#pragma once
#include "Users/User.hh"
#include "lib/MyVector.hh"
#include "lib/MyUniquePointer.hh"
#include "lib/MySharedPtr/MyWeakPtr.hh"

class Request;
class Bank;

// Something like a website/the Internet itself, providing a network connection between banks and users
class InformationSystem {
  static InformationSystem* instance;
  MyVector<MyUniquePointer<Bank>> banks = {};
  MyVector<MySharedPtr<User>> users = {}; // Heterogeneous container

  InformationSystem() = default;

public:
  InformationSystem(const InformationSystem& other) = delete;
  InformationSystem(InformationSystem&& other) = default;
  InformationSystem& operator=(const InformationSystem& other) = delete;
  InformationSystem& operator=(InformationSystem&& other) = default;
  ~InformationSystem() = default;
  static InformationSystem* getInstance();
  // Can't be used because no copying of bank employee = no cloning = no copying of MyUniquePointer
//  void addBank(const Bank& bank);
//  void addUser(User&& user);
//  void addUser(const User& user);

  void addBank(MyUniquePointer<Bank>&& bank);
  void addUser(const MySharedPtr<User>& user);

  void receiveRequest(MyUniquePointer<Request>&& request, const MyString& receiver);
  void executeRequest(MyUniquePointer<Request>&& request);
};
