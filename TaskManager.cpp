#include "TaskManager.h"
#include <iostream>
#include <algorithm>
#include <random>

// Generate a random unique ID for tasks
template <typename T>
int TaskManager<T>::generateID() {
    static std::mt19937 rng{std::random_device{}()};
    static std::uniform_int_distribution<int> dist(1000, 9999);
    return dist(rng);
}

// Add a task with a specified priority
template <typename T>
int TaskManager<T>::addTask(int priority, const T& task) {
    int id = generateID();
    tasks.insert({priority, {id, task}});
    return id;
}

// Remove a task by its unique ID
template <typename T>
void TaskManager<T>::removeTaskByID(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                           [id](const auto& pair) { return pair.second.first == id; });
    if (it != tasks.end()) {
        std::cout << "Task with ID " << id << " removed successfully: \"" << it->second.second << "\"\n";
        tasks.erase(it);
    } else {
        std::cout << "Task with ID " << id << " not found.\n";
    }
}

// Remove a task by its description
template <typename T>
void TaskManager<T>::removeTaskByDescription(const T& task) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                           [&task](const auto& pair) { return pair.second.second == task; });
    if (it != tasks.end()) {
        std::cout << "Task \"" << task << "\" removed successfully.\n";
        tasks.erase(it);
    } else {
        std::cout << "Task \"" << task << "\" not found.\n";
    }
}

// Display all tasks sorted by priority
template <typename T>
void TaskManager<T>::displayTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }
    std::cout << "Tasks in priority order:\n";
    for (const auto& [priority, pair] : tasks) {
        std::cout << "Priority: " << priority << ", ID: " << pair.first << ", Task: " << pair.second << '\n';
    }
}

// Explicit instantiation for TaskManager<std::string>
template class TaskManager<std::string>;
