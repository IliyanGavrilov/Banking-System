#include "CommandInterface.hh"
#include "../Bank.hh"
#include "Command.hh"
#include "CreateBankCmd.hh"

CommandInterface* CommandInterface::instance = nullptr;

MyVector<MyPair<const MyString, MyUniquePointer<Command>>> CommandInterface::interfaceCommands = {};
//        MyVector<MyPair<const MyString, MyUniquePointer<Command>>>
//                (MyPair<const MyString, MyUniquePointer<Command>>("a", new CreateBankCmd()), 1); TODO

CommandInterface* CommandInterface::getInstance() {
  if (!instance) {
    instance = new CommandInterface();
  }
  return instance;
}

void CommandInterface::createBank(const MyString &bankName) {
  infoSystem->addBank(bankName);
}

void CommandInterface::signup(const MyString &name, const MyString &EGN, uint8_t age,
                              MyString &userType, const MyString &associatedBankName) {
  MyString lowerUserType = toLower(userType);

  if(lowerUserType == toLower("Customer") ||
     lowerUserType == toLower("Client") ||
     lowerUserType == toLower("C")) {

    infoSystem->addUser(new Customer(name, EGN, age));
  }
  else if(lowerUserType == toLower("BankEmployee") ||
          lowerUserType == toLower("Employee") ||
          lowerUserType == toLower("BE") ||
          lowerUserType == toLower("E")) {

    infoSystem->getBank(associatedBankName)->addEmployee(BankEmployee(name, EGN, age));
  }
  else if(lowerUserType == toLower("Third-party employee") ||
          lowerUserType == toLower("ExternalEmployee") ||
          lowerUserType == toLower("ExternalCompanyEmployee") ||
          lowerUserType == toLower("EE")) {

    infoSystem->addUser(new ExternalEmployee(name, EGN, age));
  }
}

void CommandInterface::login(const MyString& name) {
  if(loggedUser) {
    throw std::out_of_range("Nullptr exception! Already logged in!");
  }
  else {
    loggedUser = infoSystem->getUser(name);
  }
}

void CommandInterface::exitCmd() {
  if(loggedUser) {
    loggedUser = nullptr;
  }
  else {
    throw std::runtime_error("Exiting program!");
  }
}

void CommandInterface::executeCommand(const MyString& command, const MyVector<MyString>& args) {
  if(!loggedUser) {
    MyUniquePointer<Command> &cmd = getCommand(command);

    cmd->execute(args);
  }
  else {
    // User.getType()
    // ...
    // cmd->execute(args);
    // TODO
  }
}

MySharedPtr<User> &CommandInterface::getLoggedUser() {
  return loggedUser;
}

MyUniquePointer<Command> &CommandInterface::getCommand(const MyString& name) {
  for(size_t i = 0; i < CommandInterface::interfaceCommands.size(); i++) {
    if(CommandInterface::interfaceCommands[i].first() == name) {
      // return CommandInterface::interfaceCommands[i].second(); TODO
    }
  }
  throw std::logic_error("Invalid command!");
}