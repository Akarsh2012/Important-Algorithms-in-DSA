// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
    private:
    // BFS function to traverse the graph
    void bfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, int root) {
        vis[root] = 1; // Mark the root node as visited
        queue<int> q; // Create a queue for BFS
        q.push(root); // Enqueue the root node
        
        while (!q.empty()) { // While there are nodes to process
            int node = q.front(); // Get the front node in the queue
            q.pop(); // Remove it from the queue
            ans.push_back(node); // Add the node to the result
            
            // Traverse all adjacent nodes
            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) { // If the adjacent node hasn't been visited
                    vis[adjNode] = 1; // Mark it as visited
                    q.push(adjNode); // Enqueue the adjacent node
                }
            }
        }
        return; // Exit the BFS function
    }
    
  public:
    // Function to perform BFS traversal of the graph
    vector<int> bfsOfGraph(vector<vector<int>>& adj) {
        int N = adj.size(); // Get the number of nodes in the graph
        vector<int> vis(N, 0); // Create a visited array initialized to 0
        vector<int> ans; // Create a result array to store the BFS traversal
        
        // Iterate through each node to cover disconnected components
        for (int i = 0; i < N; i++) {
            if (!vis[i]) { // If the node hasn't been visited
                bfs(adj, vis, ans, i); // Call BFS from that node
            }
        }
        return ans; // Return the result of the BFS traversal
    }
};

/*
    Approach:
    1. Initialize a visited array and a result array to store the BFS traversal.
    2. For each unvisited node, perform a BFS traversal starting from that node.
    3. In the BFS function, mark nodes as visited and enqueue adjacent unvisited nodes.
    4. Continue until all reachable nodes from the starting node are processed.
    5. The outer loop ensures that disconnected components are also covered.
    
    Time Complexity:
    - For undirected graphs: O(V + 2E)  // Each vertex is processed once, and each edge is visited twice
    - For directed graphs: O(V + E)     // Each vertex and each edge is processed once

    Space Complexity:
    - O(V) for the visited array, result array, and the queue.
*/
