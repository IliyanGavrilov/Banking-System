#pragma once
#include "../lib/MyString.hh"

enum class RequestType {
  OPEN,    // From customer to bank
  CHANGE1, // From customer to new bank
  CHANGE2, // From new bank to old bank (for verification/approval)
  CHANGE3, // From old bank to new bank (opening new account)
  CLOSE    // From customer to bank
};

MyString getRequestName(RequestType type);
