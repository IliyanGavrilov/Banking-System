#include "ExternalEmployee.hh"

ExternalEmployee::ExternalEmployee(const MyString& name, const MyString& EGN, uint8_t age) : User(name, EGN, age) {}

Cheque ExternalEmployee::sendCheque(int sum, const MyString& code, const MyString& egn) {
  return {sum, code, egn};
}

void ExternalEmployee::help() const {

}

User* ExternalEmployee::clone() const {
  return new ExternalEmployee(*this);
}
