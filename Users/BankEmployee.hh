#pragma once
#include "User.hh"
#include "../lib/MyQueue.hh"
#include "../Requests/Request.hh"
#include "../lib/MyUniquePointer.hh"
#include "../InformationSystem.hh"
#include "../lib/MySharedPtr/MyWeakPtr.hh"

class BankEmployee : public User {
  static MyVector<MyPair<const MyString, MyUniquePointer<Command>>> commands;
  // Should be a queue, but from the examples the employee accesses tasks by id
  MyVector<MyUniquePointer<Request>> _tasks; // Heterogeneous container
  MySharedPtr<InformationSystem> system = InformationSystem::getInstance();
  size_t taskGivenCnt = 0;
  size_t getTaskIdxById(size_t taskId) const;
public:
  // BIG 6 by disabling copying, only moving
  BankEmployee() = default; // So it can be in vector
  BankEmployee(const BankEmployee& other) = delete;
  BankEmployee(BankEmployee&& other) = default;
  BankEmployee& operator=(const BankEmployee& other) = delete;
  BankEmployee& operator=(BankEmployee&& other) = default;
  ~BankEmployee() = default;

  BankEmployee(const MyString& name, const MyString& EGN, uint8_t age);

  size_t getTasksCnt() const;
  void receiveTask(MyUniquePointer<Request>&& task);
  void listTasks() const;
  void viewTask(size_t taskId) const;
  void approve(size_t taskId);
  void disapprove(size_t taskId, const MyString& message);
  void validate(size_t taskId) const;

  void help() const override;
  void whoami() const override;
  MyUniquePointer<Command> getCommand(const MyString& cmdName) const override;
};
