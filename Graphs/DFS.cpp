class Solution {
private:
    // DFS function to explore the graph
    void dfs(vector<vector<int>>& adj, vector<int>& ans, vector<int>& vis, int root) {
        vis[root] = 1; // Mark the current node as visited
        ans.push_back(root); // Add the current node to the answer list
        
        // Iterate through all adjacent nodes of the current node
        for (auto adjNode : adj[root]) {
            if (!vis[adjNode]) { // If the adjacent node hasn't been visited
                dfs(adj, ans, vis, adjNode); // Recursive call to visit the adjacent node
            }
        }
        return; // End of the current DFS path
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> ans; // To store the DFS traversal result
        int N = adj.size(); // Number of nodes in the graph
        vector<int> vis(N, 0); // Visited array to keep track of visited nodes
        
        // Iterate through each node to cover disconnected components
        for (int i = 0; i < N; i++) {
            if (!vis[i]) { // If the node hasn't been visited
                dfs(adj, ans, vis, i); // Call DFS from that node
            }
        }
        return ans; // Return the complete DFS traversal
        // Code here
    }
};

/*
Approach:
- The function uses Depth First Search (DFS) to explore all nodes in the graph.
- It maintains a visited array to track which nodes have already been explored.
- The DFS function recursively visits all unvisited adjacent nodes starting from the root node.

Time Complexity:
- O(V + E): Each vertex and edge is visited once, where V is the number of vertices and E is the number of edges.

Space Complexity:
- O(V): The space used by the visited array and the recursion stack (in the worst case, the recursion stack can go as deep as the number of vertices).

Important Points:
- vis[root] = 1: Marks the current node as visited to avoid cycles.
- ans.push_back(root): Adds the current node to the result list.
- The for loop iterates over each adjacent node of the current node, and if an adjacent node hasn't been visited, it recursively calls the DFS function for that node.
*/
