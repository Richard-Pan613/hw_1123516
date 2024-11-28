#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/* 
    	Richard Pan
    	1123516
    	2024/11/28
*/
using namespace std;

class Task {
public:
    int profit; 
    int deadline; 

    Task(int p, int d) : profit(p), deadline(d) {} // initialize Class Task
};


struct Compare { // comparator for max-heap to prioritize tasks based on profit
    bool operator()(Task& t1, Task& t2) {
        return t1.profit < t2.profit; // return true if t1 < t2
    }
};


int scheduleTasks(vector<Task>& tasks) { // function to schedule tasks and calculate maximum profit
    sort(tasks.begin(), tasks.end(), [](Task& t1, Task& t2) { 
        return t1.deadline < t2.deadline; // sort tasks deadlines
    });

    priority_queue<Task, vector<Task>, Compare> maxHeap; // max-heap to store tasks based on profit
    int maxProfit = 0; // variable to store the total maximum profit
    vector<bool> slots(tasks.size(), false); // to track if a slot is available


    for (int i = 0; i < tasks.size(); ++i) {     // iterate through the tasks in order of deadline
        
        for (int j = tasks[i].deadline - 1; j >= 0; --j) { // check available slot at task's deadline
            if (!slots[j]) { // if slot free
                slots[j] = true;
                maxProfit += tasks[i].profit; // add the task's profit
                break; // task is scheduled, break loop
            }
        }
    }

    return maxProfit; // return total maximum profit
}

int main() {
    vector<Task> tasks = {
        Task(25, 2),
        Task(17, 2),
        Task(500, 3),
        Task(1, 1)
    };


    int maxProfit = scheduleTasks(tasks);    // call function to find the maximum profit

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
