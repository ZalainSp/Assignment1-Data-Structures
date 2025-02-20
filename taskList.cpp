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
    //Implementing removeTask


}

void TaskList::markTaskComplete(string description) {
    //Implementing markTaskComplete
    Task* task = searchTask(description);
    if(task!=complete){ //check if task is complete or not
        task = setIsComplete(true); //sets task to complete
        cout<<"Task marked as complete.";
    }else{
        cout<<"Unable to locate task.";
    }
}

void TaskList::displayAllTasks() {
    //Implement displayAllTasks
    Task* current = head;
    while(current !=nullptr){
        cout<<"Task description: "<< current->getDescription();
        cout<<" Task priotity: "<< current-> getPriority();
        cout<<" Task due date: "<< current -> getDate();
        cout<<" Status: "; 
        if (current->getIsComplete()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        
    }
    if(current ==nullptr) {
        cout<<"There are currently no tasks to display";
    }
}

void TaskList::displayByPriority(string priority) {
    //Implementing displayByPriority
    Task* current = head;
    bool search = false;

    if(current !=nullptr){
        if(current == priority){
            search = true;
            cout<<"Task description: "<< current->getDescription();
        cout<<" Task priotity: "<< current-> getPriority();
        cout<<" Task due date: "<< current -> getDate();
        cout<<" Status: ";
        cout<<" Status: "; 
        if (current->getIsComplete()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        }
        if(current!=priority){
            cout<<"No task with "<<priority<< " was found.";
        }
    }
}

Task* TaskList::searchTask(string description)  {
    // TODO: Implement searchTask
}

int TaskList::getTaskCount() {
     //Implement getTaskCount
     return count; //return the count

}
