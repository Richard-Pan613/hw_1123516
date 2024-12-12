#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> createAdjacencyList(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adjacencyList(V); // initialize the adjacency list with V vertices

    for (auto& edge : edges) { // populate the adjacency list with the edges
        int u = edge[0] - 1;  // Adjust the indexing to 0-based
        int v = edge[1] - 1;  // Adjust the indexing to 0-based

        adjacencyList[u].push_back(v); // connect both nodes to each other
        adjacencyList[v].push_back(u);
    }

    // sort each adjacency list for consistency (optional, depends on requirements)
    for (int i = 0; i < V; i++) {
        sort(adjacencyList[i].begin(), adjacencyList[i].end());
    }

    return adjacencyList;
}

int main() {
    int V = 5; // V for vertices (adjusted to 5 as the highest vertex is 5)
    int E = 7; // E for edges

    vector<vector<int>> adj = { // input edges
        {5, 3}, {2, 4}, {1, 3}, {2, 1}, {5, 1}, {2, 3}, {4, 1}
    };

    vector<vector<int>> adjacencyList = createAdjacencyList(V, adj); // call to createAdjacencyList()

    // Output the adjacency list
    for (int i = 0; i < adjacencyList.size(); i++) {
        cout << i + 1 << ": [ ";
        for (int node : adjacencyList[i]) {
            cout << node + 1 << " "; // Adjust the output back to 1-based indexing
        }
        cout << "]" << endl;
    }

    return 0;
}
