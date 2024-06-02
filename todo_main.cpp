#include <iostream>
#include "todo_list.h"
#include "security.h" // Include the security system header

int main() {
    int choice;
    std::string task, newTask;
    int taskId;
    TodoList todoList;

    // Security system initialization
    if (!loginSystem()) {
        std::cout << "Login failed. Exiting application." << std::endl;
        return 1;
    }

    do {
        std::cout << "\nTo-Do List Application\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Edit Task\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. List Tasks\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::cin.ignore();
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            case 2:
                std::cout << "Enter task ID to edit: ";
                std::cin >> taskId;
                std::cout << "Enter new task: ";
                std::cin.ignore();
                std::getline(std::cin, newTask);
                todoList.editTask(taskId, newTask);
                break;
            case 3:
                std::cout << "Enter task ID to delete: ";
                std::cin >> taskId;
                todoList.deleteTask(taskId);
                break;
            case 4:
                todoList.listTasks();
                break;
            case 5:
                std::cout << "Exiting application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
