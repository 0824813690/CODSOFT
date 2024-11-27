#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Task {
    string description;
    bool isCompleted;
};


void Menu() {
    cout << "****TO-DO LIST MANAGER****"<< endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks"<< endl;
    cout << "3. Mark Task as Completed"<< endl;
    cout << "4. Remove Task"<< endl;
    cout << "5. Exit"<< endl;
    cout << "** ENTER YOUR OPTION: "<< endl;
}


void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task description: "<< endl;
    cin.ignore();
    getline(cin, taskDescription);
    tasks.push_back({taskDescription, false});
    cout << "Task added successfully!"<< endl;
}


void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display."<< endl;
        return;
    }
    cout << "****TO-DO LIST****"<<endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]"<< endl;
    }
}


void markTaskCompleted(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}


void removeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "choose number of Tasking you want to remove: "<< endl;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!"<< endl;
    } else {
        cout << "Invalid task number! "<< endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        Menu();
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            markTaskCompleted(tasks);
        } else if (choice == 4) {
            removeTask(tasks);
        } else if (choice == 5) {
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
