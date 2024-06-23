#include "User.hh"

User::User(const MyString& name, const ID& EGN, uint8_t age) : EGN(EGN) {
  if(name.length() <= 1) {
    throw std::invalid_argument("Name must have length of at least 2 characters to be valid!");
  }

  for(size_t i = 0; i < name.length(); i++) {
    if(!isAlpha(name[i])) {
      throw std::invalid_argument("Name contains symbols that aren't letters!");
    }
  }

  if(!isUpper(name[0])) {
    throw std::invalid_argument("Name must start with an uppercase letter!");
  }

  // Could check if age is at least 18

  this->name = name;
  this->age = age;
}

void User::whoami() {
  std::cout << "You are " << name << "!\n";
}

const MyString &User::getName() const {
  return name;
}
