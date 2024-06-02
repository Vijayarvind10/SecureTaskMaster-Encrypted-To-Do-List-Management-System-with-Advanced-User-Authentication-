#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <string>
#include <unordered_map>

class TodoList {
public:
    TodoList();
    void addTask(const std::string& task);
    void editTask(int id, const std::string& newTask);
    void deleteTask(int id);
    void listTasks() const;

private:
    std::unordered_map<int, std::string> tasks;
    int nextId;
};

#endif // TODO_LIST_H
