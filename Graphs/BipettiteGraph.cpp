
// Bipartite means marking the nodes with two colors such that no two adjacent nodes have the same color 

class Solution {
    private:
    
    // BFS function to check if the graph can be colored using 2 colors (0 and 1) without conflicts
    bool bfs(vector<vector<int>> & adj, vector<int> & vis, int root) {
        vis[root] = 1; // Assign the root node to one set (arbitrarily using color 1)
        queue<int> q;
        q.push(root);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
           
            // Traverse all adjacent nodes of the current node
            for (auto adjNode : adj[node]) {
                if (vis[adjNode] == -1) { // If adjacent node is unvisited
                    vis[adjNode] = !vis[node]; // Assign it the opposite color (flip 0 <-> 1)
                    q.push(adjNode); // Add the adjacent node to the queue
                } 
                // If adjacent node has the same color as the current node, the graph is not bipartite
                else if (vis[adjNode] == vis[node]) {
                    return false; // A conflict is found, so the graph is not bipartite
                }
            }
        }
        return true; // No conflicts found, so this component is bipartite
    }

public:
    // Approach: 
    // 1. Use BFS to traverse the graph and assign two colors to nodes.
    // 2. Start from any unvisited node and check if all connected nodes can be colored alternately.
    // 3. If any two adjacent nodes are colored the same, return false (graph is not bipartite).
    // 4. Repeat for all components of the graph if it's disconnected.
    
    // Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    // Space Complexity: O(V) for the 'vis' array and the queue used in BFS.
    bool isBipartite(vector<vector<int>>& adj) {
        int N = adj.size(); // Number of nodes in the graph
        vector<int> vis(N, -1); // Visited array to track colors: -1 means unvisited, 0 and 1 are the two sets
        
        // Check all components of the graph (necessary if graph is disconnected)
        for (int i = 0; i < N; i++) {
            if (vis[i] == -1) { // If the node is unvisited
                // Perform BFS from the unvisited node and check for bipartiteness
                if (!bfs(adj, vis, i)) return false; // If any component is not bipartite, return false
            }
        }
        return true; // All components are bipartite, so return true
    }
};
