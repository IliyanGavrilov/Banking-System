#pragma once

#include "../Users/User.hh"
#include "../Users/Customer.hh"
#include "../Users/BankEmployee.hh"
#include "../Users/ExternalEmployee.hh"

class Command;

class CommandInterface {
  // Map would be fastest
  static CommandInterface* instance;
  static MyVector<MyPair<const MyString, MyUniquePointer<Command>>> interfaceCommands;
  MySharedPtr<User> loggedUser = nullptr;
  MyUniquePointer<InformationSystem> infoSystem = InformationSystem::getInstance();

  CommandInterface() = default;

public:
  CommandInterface(const CommandInterface& other) = delete;
  CommandInterface(CommandInterface&& other) = default;
  CommandInterface& operator=(const CommandInterface& other) = delete;
  CommandInterface& operator=(CommandInterface&& other) = default;
  ~CommandInterface() = default;
  static CommandInterface* getInstance();

  MySharedPtr<User> &getLoggedUser();
  MyUniquePointer<Command> &getCommand(const MyString& name);

  void executeCommand(const MyString& command, const MyVector<MyString>& args);
  // Commands
  void createBank(const MyString& bankName);
  void signup(const MyString& name, const MyString& EGN, uint8_t age, MyString& userType, const MyString& associatedBankName = "");
  void login(const MyString& name);
  void exitCmd();
};
