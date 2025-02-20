#include "taskList.h"
#include <iostream>
using namespace std;

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
    //Implementing addTask
Task *newTask = new Task(description, priority, dueDate); //create a new task
Task* existingTask = searchTask(description); //create a existingtask variable 
if(newTask == existingTask){ //check the list if a task with the same description already exists
    cout<< description <<" already exists";
    return;
}

if(head ==nullptr){
    head = tail = newTask; //if the list is empty newTask is both the head and the tail
}else{
    tail->setNext(newTask); //adds the new task at the end
    tail = newTask; //the new task is now the tail
}
count++; //increment the amount of tasks
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
