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
if(existingTask != nullptr){ //check the list if a task with the same description already exists
    cout<< description <<" already exists";
    delete newTask;
    newTask = nullptr;
    return;
}

if(head ==nullptr){
    head = tail = newTask; //if the list is empty newTask is both the head and the tail
}else{
    tail->setNext(newTask); //adds the new task at the end
    tail = newTask; //the new task is now the tail
}
count++; //increment the amount of tasks
cout<<"Task Added."<<'\n';
}

void TaskList::removeTask(string description) {
    //Implementing removeTask
    if(head == nullptr) {
        return; // Early exit if the list is empty
    }

    Task *current = head;
    Task *previous = nullptr;

    

    while(current ->getDescription() !=description && current != nullptr) //loop to search for task and make sure the search 
    {                                                                     //doesnt go past the end of list
    previous = current;
    current = current ->getNext();
    }

    if(current == nullptr){ //if statement if the task is not found
        cout<<"Unable to find task"; 
        return;
    }

    if (previous == nullptr) {      
        head = current->getNext(); //set head to the next node, deleting it
    } else {
        previous->setNext(current->getNext()); //set the previous node next pointer to the current nodes next poitner
    }

    if (current == tail) { //set tail to the previous node after removing the task
        tail = previous;
    }

    delete current; //free memory
    current = nullptr; //avoid dangling pointer
    count--;        //decrement task count
    cout << "Task removed successfully"<<'\n';


}

void TaskList::markTaskComplete(string description) {
    //Implementing markTaskComplete
    if(head == nullptr) {
        return; // Early exit if the list is empty
    }

    Task* task = searchTask(description);
    if(task!=nullptr){ //check if task is complete or not
        task -> setIsComplete(true); //sets task to complete
        cout<<"Task marked as complete."<<'\n';
    }else{
        cout<<"Unable to locate task."<<'\n';
    }
}

void TaskList::displayAllTasks() {
    //Implement displayAllTasks
    if(head == nullptr) {
        return; // Early exit if the list is empty
    }

    Task* current = head;
    while(current !=nullptr){ //if statement to print task info if current location is not null
        cout<<"Task description: "<< current->getDescription();
        cout<<",  Task priotity: "<< current-> getPriority();
        cout<<",  Task due date: "<< current -> getDueDate();
        cout<<",  Status: "; 
        if (current->getIsComplete()) { //if statement to print yes or no instead of 1 or 0
            cout << "completed\n";
        } else {
            cout << "incomplete\n";
        }
        current = current->getNext(); //move to next task
        
    }
    
}

void TaskList::displayByPriority(string priority) {
    //Implementing displayByPriority
    if(head == nullptr) {
        return; // Early exit if the list is empty
    }

    Task* current = head;
    bool search = false;

    if(current !=nullptr){
        if(current->getPriority() == priority){ //if statement if priority was found, prints all task info
            search = true;
            cout<<"Task description: "<< current->getDescription();
        cout<<"  ,Task priotity: "<< current-> getPriority();
        cout<<"  ,Task due date: "<< current -> getDueDate();
        cout<<"  ,Status: "; 
        if (current->getIsComplete()) { //if statement to print yes or no instead of 1 or 0
            cout << "completed\n";
        } else {
            cout << "incomplete\n";
        }
        current = current ->getNext(); //move to next task
        }
        if(!search){ //if statement if priority was not found
            cout<<"No task with "<<priority<< " was found.";
        }
    }
}

Task* TaskList::searchTask(string description)  {
    //Implementing searchTask
    if (head == nullptr) { //if the list is empty
        return nullptr; 
    }

    Task* current = head;
    while(current!=nullptr){
        if(current->getDescription() == description){
        return current;
    }
    current = current ->getNext(); //move to next task
}
    return nullptr;
}

int TaskList::getTaskCount() {
     //Implement getTaskCount
     return count;
     

}
