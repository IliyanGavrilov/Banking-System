#include "ExternalEmployee.hh"

ExternalEmployee::ExternalEmployee(const MyString& name, const MyString& EGN, uint8_t age) : User(name, EGN, age) {}

Cheque ExternalEmployee::sendCheque(int sum, const MyString& code, const MyString& egn) {
  return {sum, code, egn};
}

void ExternalEmployee::help() const {
  User::help();
  std::cout << "send_check [sum] [verification_code] [egn] - Creates cheque for user with given EGN.\n";
}

void ExternalEmployee::whoami() const {
  User::whoami();
  std::cout << "(External Company Employee)!\n";
}