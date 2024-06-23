#include "Messages.hh"
#include <iostream> // cout

void Messages::receive(const MyString& message) {
  messages.push_back(message);
}

void Messages::receive(MyString&& message) {
  messages.push_back(std::move(message));
}

void Messages::list() {
  for(size_t i = 0; i < messages.size(); i++) {
    std::cout << "[" << i + 1 << "] - " << messages[i] << "\n";
  }
}