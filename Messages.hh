#pragma once
#include "lib/MyVector.hh"
#include "lib/MyString.hh"

class Messages {
  MyVector<MyString> messages;
public:
  void receive(const MyString& message);
  void receive(MyString&& message);
  void list() const;
};
