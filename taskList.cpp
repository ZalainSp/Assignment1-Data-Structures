#include "taskList.h"

// Setup a new TaskList
TaskList::TaskList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

TaskList::~TaskList() {
    // Implementing the destructor 
    Task *current = head;
    while(head!=nullptr){
        Task *next = current->getNext(); //get the next task
        delete current; //delete the task
        current = next; // move to the next task
    }
}

void TaskList::addTask(string description, string priority, string dueDate) {
    // TODO: Implement addTask
}

void TaskList::removeTask(string description) {
    // TODO: Implement removeTask
}

void TaskList::markTaskComplete(string description) {
    // TODO: Implement markTaskComplete
}

void TaskList::displayAllTasks() {
    // TODO: Implement displayAllTasks
}

void TaskList::displayByPriority(string priority) {
    // TODO: Implement displayByPriority
}

Task* TaskList::searchTask(string description)  {
    // TODO: Implement searchTask
}

int TaskList::getTaskCount() {
     // TODO: Implement getTaskCount

}
