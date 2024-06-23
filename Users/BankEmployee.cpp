#include "BankEmployee.hh"
#include "../Commands/TasksCmd.hh"

MyVector<MyPair<const MyString, MyUniquePointer<Command>>> BankEmployee::commands = {};
        //{MyPair<const MyString, MyUniquePointer<Command>>("a", new TasksCmd(*this)),}; TODO

BankEmployee::BankEmployee(const MyString& name, const MyString& EGN, uint8_t age) : User(name, EGN, age) {}

size_t BankEmployee::getTaskIdxById(size_t taskId) const {
  for(size_t i = 0; i < _tasks.size();i++) {
    if(_tasks[i]->getId() == taskId) {
      return i;
    }
  }
  throw std::logic_error("No task with given id exists!");
}

size_t BankEmployee::getTasksCnt() const {
  return _tasks.size();
}

void BankEmployee::receiveTask(MyUniquePointer<Request>&& task) {
  taskGivenCnt++;
  task->setId(taskGivenCnt);
  _tasks.push_back(std::move(task));
}

void BankEmployee::listTasks() const {
  for(size_t i = 0; i < _tasks.size(); i++) {
    (*_tasks[i]).shortDesc();
  }
}

void BankEmployee::viewTask(size_t taskId) const {
  _tasks[getTaskIdxById(taskId)]->description();
}

void BankEmployee::approve(size_t taskId) {
  // You opened an account in EntranceInvest! Your account id is 777
  // You changed your savings account to Health_Savings_Accounts. New account id is 2903.
  // Your Close request was not approved. Reason: Why don't you spend your money?
  MyUniquePointer<Request> task = std::move(_tasks[getTaskIdxById(taskId)]);
  _tasks.pop(getTaskIdxById(taskId));
  system->executeRequest(std::move(task));
}

void BankEmployee::disapprove(size_t taskId, const MyString& message) {
  _tasks[getTaskIdxById(taskId)]->respond("Your " +
    getRequestName(_tasks[getTaskIdxById(taskId)]->getType()) + " request was not approved. Reason: " + message);

  _tasks.pop(getTaskIdxById(taskId));
}

void BankEmployee::validate(size_t taskId) const {
  // TODO
}

void BankEmployee::help() const {
  User::help();
  std::cout << "tasks - Lists all your undone tasks, along with a short description.\n";
  std::cout << "view [task_id] - Shows full detailed description regarding a given task.\n";
  std::cout << "approve [task_id] - Approve and finish task.\n";
  std::cout << "disapprove [task_id] - Disapprove and finish task.\n";
  std::cout << "validate [task_id] - Sends request to old bank for validation whether the user has inputted correct data.\n";
}

void BankEmployee::whoami() const {
  User::whoami();
  std::cout << "(Bank Employee)!\n";
}

MyUniquePointer<Command> BankEmployee::getCommand(const MyString &cmdName) const {
  return MyUniquePointer<Command>();
}
