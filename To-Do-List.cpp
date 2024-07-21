#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ToDoList {
public:
    vector<string> list = {"list is empty"};

    void addTask();
    void viewTask(int n);
    void viewAllTasks();
    void removeTask();
    void markAsCompleted();
    void updateTask();
    void menu();
};

void ToDoList::updateTask() {
    viewAllTasks();
    cout << "\nPlease select a task number to Update: ";
    int n;
    cin >> n;

    if (n > 0 && n < list.size()) {
        cout << "Please edit the task: ";
        string temp;
        cin.ignore();
        getline(cin, temp);
        list[n] = temp;
        cout << "\nTask '" << list[n - 1] << "' is Updated" << endl;
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

void ToDoList::removeTask() {
    viewAllTasks();
    cout << "\nPlease select a task number to Delete: ";
    int n;
    cin >> n;

    if (n > 0 && n < list.size()) {
        cout << "\nTask '" << list[n - 1] << "' is Deleted" << endl;
        list.erase(list.begin() + (n - 1));
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

void ToDoList::viewAllTasks() {
    cout << "\n-------------------------------------" << endl;
    if (list.size() == 1) {
        cout << list[0] << endl;
    } else {
        for (int i = 1; i < list.size(); i++) {
            cout << i << ". " << list[i] << endl;
        }
    }
    cout << "-------------------------------------" << endl;
}

void ToDoList::viewTask(int n) {
    cout << list[n] << endl;
}

void ToDoList::addTask() {
    cout << "\n-------------------------------------" << endl;
    cout << "Please add your task " << list.size() << ": ";
    string temp;
    cin.ignore();
    getline(cin, temp);
    list.push_back(temp);
    cout << "Task '" << list.back() << "' is successfully added to your list."
         << endl;
    cout << "-------------------------------------" << endl;
}

void ToDoList::markAsCompleted() {
    viewAllTasks();
    cout << "\nPlease select a task number to mark as completed: ";
    int n;
    cin >> n;

    if (n > 0 && n < list.size()) {
        cout << "\nTask '" << list[n - 1] << "' is completed" << endl;
        list.erase(list.begin() + (n - 1));
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

void ToDoList::menu() {
    while (true) {
        cout << "\n-------------------------------" << endl;
        cout << "          TASK MANAGER" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Add a New Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Update Task" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewAllTasks();
                break;
            case 3:
                markAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                updateTask();
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    ToDoList list1;
    list1.menu();
    return 0;
}
