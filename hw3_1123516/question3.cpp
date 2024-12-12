#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int vertex, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {

    visited[vertex] = true; // mark the current vertex as visited

    result.push_back(vertex);    // add the vertex to the result list


    for (int neighbor : adj[vertex]) { // visit all the neighbors of the current vertex
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfs(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);  // initialize visited list with false
    vector<int> result;  // initialize the result list to store the DFS traversal

    // Start DFS from vertex 0
    dfsHelper(0, adj, visited, result);

    return result;
}

int main() {

    vector<vector<int>> adj = { //input
        {3, 4},      // vertex 0 is connected to 3 and 4
        {2,3},      // vertex 1 is connected to 2 and 3
        {0,1, 4}, // vertex 2 is connected to 0, 1, and 4
        {1},         // vertex 3 is connected to 1
        {2}          // vertex 4 is connected to 2
    };


    vector<int> result = dfs(adj);  // perform DFS


    for (int vertex : result) {     // output
        cout << vertex << " ";
    }

    return 0;
}
