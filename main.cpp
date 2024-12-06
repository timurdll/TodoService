#include "TaskManager.h"

int main() {
    TaskManager<std::string> todoList;

    // Adding tasks
    int id1 = todoList.addTask(2, "Complete project report");
    int id2 = todoList.addTask(1, "Attend team meeting");
    int id3 = todoList.addTask(3, "Prepare presentation");

    // Display tasks
    todoList.displayTasks();

    // Remove a task by description
    todoList.removeTaskByDescription("Complete project report");

    // Remove a task by ID
    todoList.removeTaskByID(id2);

    // Display tasks after removals
    todoList.displayTasks();

    // Attempt to remove a non-existing task by ID
    todoList.removeTaskByID(9999);

    return 0;
}
