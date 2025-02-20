#include "taskList.h"
#include <iostream>
#include <string>

void displayMenu() {
	cout << "\n=== Task Manager Menu ===\n"
	     << "1. Add New Task\n"
	     << "2. Remove Task\n"
	     << "3. Mark Task as Complete\n"
	     << "4. Display All Tasks\n"
	     << "5. Display Tasks by Priority\n"
	     << "6. Search for Task\n"
	     << "7. Exit\n"
	     << "Enter your choice: ";
}

int main() {

	TaskList taskList;
	int choice;
	string description;
	string priority;
	string dueDate;

	while (true) {
		displayMenu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1: {
			cout << "Enter task description: ";
			getline(cin, description);
			cout << "Enter priority (High/Medium/Low): ";
			getline(cin, priority);
			cout << "Enter due date: ";
			getline(cin, dueDate);
			taskList.addTask(description, priority, dueDate);
			break;
		}
		case 2: {
			cout<< "Enter task you'd like to remove: ";
			getline(cin, description);
			taskList.removeTask(description);
			break;
		}
		case 3: {
			cout<< "Enter task you'd like to mark as complete: ";
			getline(cin, description);
			taskList.markTaskComplete(description);
			break;
		}
		case 4: {
			taskList.displayAllTasks();
			break;
		}
		case 5: {
			cout<< "Enter desired priority: ";
			getline(cin, priority);
			taskList.displayByPriority(priority);
			break;
		}
		case 6: {
			cout << "Enter task description to search: ";
			getline(cin, description);
			Task* task = taskList.searchTask(description);
			if (task != nullptr) {
				cout << "Task found:\n";
				     cout<<"Task description: "<<task->getDescription();
				cout<<",  Task priotity: "<<task->getPriority();
				cout<<",  Task due date: "<<task->getDueDate();
				cout<<",  Status: "<<(task->getIsComplete() ? "Completed" : "Incomplete") << "\n"; 
					
				} else {
					cout << "Task not found.\n";
				}
				break;
			}

			case 7: {
				cout<< "exiting";
				return 0;
			}

			default: {
				cout<<"Please enter a valid choice.";
				break;
			}

		}
		}
		return 0;
	}