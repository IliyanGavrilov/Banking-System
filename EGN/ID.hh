#pragma once
#include "../lib/MyString.hh"
#include "IDRegion.hh"
#define EGN_LEN 10
#define MOD 11 // The checkSum number is reduced to mod11 (module 11)

class ID {
  char EGN[EGN_LEN + 1] = "0001010003";
  IDRegion region = IDRegion::Blagoevgrad;

  void setEGN(const MyString &str);
public:
  ID() = default;
  ID(const MyString& str); // NOT EXPLICIT

  const char *getEGN() const;
  void validateEGN(const MyString &str) const;

  // How many people (of same gender) born on the same day in the same region before this person
  size_t peopleBornBefore();

  // Is girl or boy
  bool isBoy() const;
  bool isGirl() const;

  friend bool operator==(const ID& id1, const ID& id2);
  friend std::ostream& operator<<(std::ostream& os, const ID& egn);
};
