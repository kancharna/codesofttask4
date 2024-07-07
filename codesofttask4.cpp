#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool done;
};
void showMenu() {
   cout<<" \n 1. Add Task\n 2. View Tasks\n 3. Mark Task as Completed\n 4. Remove Task\n 5. Exit\n"<<endl;
}
void addTask(vector<Task>& tasks) {
    string name;
    cout << "Enter a new task: ";
    cin.ignore();
    getline(cin, name);
    tasks.push_back({name, false});
    cout << "Task added.\n";
}
void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].done ? "Completed" : "Pending") << "]\n";
    }
}
void markTaskDone(vector<Task>& tasks)
 {
    int num;
    cout << "Enter the task number to mark as completed: ";
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].done = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
 }
void removeTask(vector<Task>& tasks) {
    int num;
    cout << "Enter the task number to remove: ";
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}
int main() {
    vector<Task> tasks;
    int choice;
    while (true) {
        showMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskDone(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
