#include "RequestType.hh"
#include <exception>

MyString getRequestName(RequestType type) {
  switch(type) {
    case RequestType::OPEN: return {"Open"};
    case RequestType::CHANGE1: case RequestType::CHANGE2: case RequestType::CHANGE3: return {"Change"};
    case RequestType::CLOSE: return {"Close"};
  }
  throw std::logic_error("No such RequestType exists!");
}