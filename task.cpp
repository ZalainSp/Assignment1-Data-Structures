#include "task.h"

// Setup a new Task
Task::Task(string desc, string prio, string date) {
    description = desc;
    priority = prio;
    dueDate = date;
    isComplete = false;
    next = nullptr;
}

string Task::getDescription() {
    //Returns the description of this task
    return description;
}

string Task::getPriority() {
    //Returns the priority of this task
    return priority;
}

string Task::getDueDate() {
    //Returns the due date of this task
    return dueDate;
}

bool Task::getIsComplete() {
    //Returns whether the task is complete or not
    return isComplete;
}

Task* Task::getNext() {
    //Returns pointer to the next task in the list
    return next;
}

void Task::setDescription(string desc) {
    //Set the description of this task to desc
    description = desc;
}

void Task::setPriority(string prio) {
    //Set the priority of this task to prio
    priority = prio;
}

void Task::setDueDate(string date) {
    //Set the due date of this task to date
    dueDate = date;
}

void Task::setIsComplete(bool complete) {
    //Set the completion status of this task to complet
    isComplete = complete;
}

void Task::setNext(Task* nextTask) {
    // Set the next pointer to nextTask
    next = nextTask;
}