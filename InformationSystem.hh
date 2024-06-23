#pragma once
#include "Users/User.hh"
#include "lib/MyVector.hh"
#include "lib/MyUniquePointer.hh"
#include "lib/MySharedPtr/MyWeakPtr.hh"
#include "EGN/ID.hh"

class Request;
class Bank;

// Something like a website/the Internet itself, providing a network connection between banks and users
class InformationSystem {
  static InformationSystem* instance;
  MyVector<MyUniquePointer<Bank>> banks = {};
  MyVector<MySharedPtr<User>> users = {}; // Heterogeneous container
  // TODO I didn't have time to finish this, but the customer sends a redeem "request" and the system checks if it is valid and gives it to
  // him, otherwise it doesn't
  // And the ExternalEmployee's method gets used and gets added to this vector here
  MyVector<MySharedPtr<Cheque>> notRedeemedCheques = {};

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

  MySharedPtr<User> &getUser(const MyString& name);
  MyUniquePointer<Bank> &getBank(const MyString& associatedBankName);

  void addBank(MyUniquePointer<Bank>&& bank);
  void addBank(const MyString& bankName);
  void addUser(const MySharedPtr<User>& user, const MyString& associatedBankName = "");

  void redeemCheque(const ID& EGN, const MyString &bankName, size_t accountNumber, const MyString &verification_code);
  void receiveRequest(MyUniquePointer<Request>&& request, const MyString& receiver);
  void executeRequest(MyUniquePointer<Request>&& request);
};
