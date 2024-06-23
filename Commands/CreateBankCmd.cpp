#include "CreateBankCmd.hh"

void CreateBankCmd::execute(const MyVector<MyString>& args) const {
  CommandInterface::getInstance()->createBank(args[0]);
}
