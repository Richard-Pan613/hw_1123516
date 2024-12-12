#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(const vector<vector<int>>& adj) {
    int n = adj.size();  // how many vertices in the tree
    vector<int> result;  // BFS traversal result
    vector<bool> visited(n, false);  // to track visited vertices
    queue<int> q;  // queue for performing BFS


    visited[0] = true; //start BFS from 0
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop(); // dequeue a vertex
        result.push_back(current);  // add to result


        for (int neighbor : adj[current]) { //To travels all neighbors of the current vertex
            if (!visited[neighbor]) {
                visited[neighbor] = true;  // mark neighbor as visited
                q.push(neighbor);  // queue the neighbor
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> adj = {{3, 2, 1}, {0}, {0,4}, {0}, {2}}; //inputs

    vector<int> bfsOrder = bfsTraversal(adj);


    for (int node : bfsOrder) { //outputs
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
