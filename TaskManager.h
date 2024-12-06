#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <map>
#include <string>

template <typename T>
class TaskManager {
private:
    std::multimap<int, std::pair<int, T>> tasks; // Priority as key, pair<ID, Task> as value
    int generateID(); // Generate a unique ID for tasks

public:
    int addTask(int priority, const T& task);       // Add a task with specified priority
    void removeTaskByID(int id);                   // Remove a task by ID
    void removeTaskByDescription(const T& task);   // Remove a task by description
    void displayTasks() const;                     // Display all tasks sorted by priority
};

#endif // TASK_MANAGER_H
