#include "Counter.hh"

void Counter::removeSharedPtr()
{
  useCount--;
  if(useCount == 0) {
    weakCount--;
  }
}
void Counter::removeMyWeakPtr()
{
  weakCount--;
}

void Counter::addSharedPtr()
{
  useCount++;
  if(useCount == 1) {
    weakCount++;
  }
}

void Counter::addMyWeakPtr()
{
  weakCount++;
}

unsigned int Counter::getUseCount() const {
  return useCount;
}

unsigned int Counter::getWeakCount() const {
  return weakCount;
}
