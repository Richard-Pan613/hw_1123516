#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int minSpanningTreeWeight(int V, vector<vector<pair<int, int>>>& adj) {
    int mstWeight = 0;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     // priority queue to store the edges, ordered by the weight

    vector<bool> inMST(V, false); // array to check if a node is included in the MST

    pq.push({0, 0});  // (weight, node)

    while (!pq.empty()) {
        int weight = pq.top().first; // extract the edge with the minimum weight
        int u = pq.top().second;
        pq.pop();


        if (inMST[u]) { // if the node is already in MST, continue to the next edge
            continue;
        }


        inMST[u] = true;// include the node in the MST and add its weight to the MST total
        mstWeight += weight;


        for (const auto& edge : adj[u]) { // explore all the adjacent nodes of u
            int v = edge.first;
            int w = edge.second;


            if (!inMST[v]) { // if v is not in the MST, push it to the priority queue
                pq.push({w, v});
            }
        }
    }

    return mstWeight;
}

int main() {
    int V = 3;  // number of vertices
    int E = 3;  // number of edges


    vector<vector<pair<int, int>>> adj(V); // input


    adj[0].push_back({1, 0}); // add the edges to the adjacency list
    adj[0].push_back({2, 5});
    adj[1].push_back({0, 0});
    adj[1].push_back({2, 7});
    adj[2].push_back({0, 5});
    adj[2].push_back({1, 7});


    int mstWeight = minSpanningTreeWeight(V, adj); //call the function to compute the MST weight


    cout << mstWeight << endl;//output

    return 0;
}
