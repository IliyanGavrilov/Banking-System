#pragma once

class Counter {
  unsigned int useCount = 0;
  unsigned int weakCount = 0;

public:
  unsigned int getUseCount() const;

  unsigned int getWeakCount() const;

  void removeSharedPtr();
  void removeMyWeakPtr();
  void addSharedPtr();
  void addMyWeakPtr();

};
