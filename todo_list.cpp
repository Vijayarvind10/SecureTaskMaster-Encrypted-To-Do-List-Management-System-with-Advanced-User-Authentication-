#include "todo_list.h"
#include <iostream>

TodoList::TodoList() : nextId(1) {}

void TodoList::addTask(const std::string& task) {
    tasks[nextId] = task;
    std::cout << "Task added with ID: " << nextId << std::endl;
    nextId++;
}

void TodoList::editTask(int id, const std::string& newTask) {
    if (tasks.find(id) != tasks.end()) {
        tasks[id] = newTask;
        std::cout << "Task " << id << " updated." << std::endl;
    } else {
        std::cout << "Task ID not found." << std::endl;
    }
}

void TodoList::deleteTask(int id) {
    if (tasks.find(id) != tasks.end()) {
        tasks.erase(id);
        std::cout << "Task " << id << " deleted." << std::endl;
    } else {
        std::cout << "Task ID not found." << std::endl;
    }
}

void TodoList::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
    } else {
        for (const auto& task : tasks) {
            std::cout << "ID: " << task.first << ", Task: " << task.second << std::endl;
        }
    }
}
