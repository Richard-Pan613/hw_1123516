#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    string name; 
    int priority; 

    Task(string n, int p) : name(n), priority(p) {} // Constructor to initialize task with name and priority
};


bool compare(Task& t1, Task& t2) { // Function to compare tasks based on priority for the max heap
    return t1.priority < t2.priority; // For max heap, larger priority should come first
}


void heapify(vector<Task>& tasks, int n, int i) { // Function to implement heap sort on tasks
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    if (left < n && tasks[left].priority > tasks[largest].priority)    // If left child is larger than root
        largest = left;


    if (right < n && tasks[right].priority > tasks[largest].priority)     // If right child is larger than root or left child
        largest = right;


    if (largest != i) {     // If largest is not root
        swap(tasks[i], tasks[largest]); // Swap root with largest child


        heapify(tasks, n, largest);// Recursively heapify the affected subtree
    }
}


void heapSort(vector<Task>& tasks) { // Function to perform heap sort on the tasks vector
    int n = tasks.size();


    for (int i = n / 2 - 1; i >= 0; i--) { // Build the heap (rearrange the array)
        heapify(tasks, n, i); // heapify the subtree rooted at index i
    }
}

int main() {
    int N;
    cin >> N; 

    vector<Task> taskQueue; // Vector to store tasks in the priority queue
    vector<Task> completedTasks; // Vector to store completed tasks

    for (int i = 0; i < N; i++) {
        string operation;
        cin >> operation; // Read operation type

        if (operation == "ADD") { // If operation is to add a task
            string taskName;
            int priority;
            cin >> taskName >> priority; // Input task name and priority

            taskQueue.push_back(Task(taskName, priority)); // Add task to taskQueue
        } 
        else if (operation == "GET") { // If operation is to get the highest priority task
            if (!taskQueue.empty()) {
                
                heapSort(taskQueue); // Rearrange tasks to maintain max heap property


                cout << taskQueue[0].name << endl;
                completedTasks.push_back(taskQueue[0]);
                taskQueue.erase(taskQueue.begin()); // Remove the highest priority task from the queue
            }
        }
    }

    
    cout << "Remaining tasks: ["; // After all operations, print remaining tasks in descending order of priority
    for (int i = 0; i < taskQueue.size(); i++) {
        cout << "(" << taskQueue[i].name << ", " << taskQueue[i].priority << ")";
        if (i != taskQueue.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
