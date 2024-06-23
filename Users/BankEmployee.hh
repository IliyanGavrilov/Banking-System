#pragma once
#include "User.hh"
#include "../lib/MyQueue.hh"
#include "../Requests/Request.hh"
#include "../lib/MyUniquePointer.hh"
#include "../InformationSystem.hh"
#include "../lib/MySharedPtr/MyWeakPtr.hh"

class BankEmployee : public User {
  // Should be a queue, but from the examples the employee accesses tasks by id
  MyVector<MyUniquePointer<Request>> _tasks; // Heterogeneous container
  MySharedPtr<InformationSystem> system;
  size_t taskGivenCnt = 0;
  size_t getTaskIdxById(size_t taskId) const;
public:
  BankEmployee() = default; // So it can be in vector
  size_t getTasksCnt() const;
  void receiveTask(MyUniquePointer<Request>&& task);
  void listTasks() const;
  void viewTask(size_t taskId) const;
  void approve(size_t taskId);
  void disapprove(size_t taskId, const MyString& message);
  void validate(size_t taskId) const;

  void help() const override;
  User* clone() const override;
};
