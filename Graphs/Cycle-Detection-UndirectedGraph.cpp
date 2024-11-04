// 1.Using BFS

class Solution {
private:
    // BFS function to detect a cycle in the graph
    bool bfs(vector<vector<int>>& adj, vector<int>& vis, int root) {
        vis[root] = 1; // Mark the starting node as visited
        queue<pair<int, int>> q; // Queue to perform BFS; pair stores (current_node, parent_node)
        q.push({root, -1}); // Initialize queue with the root node and its parent (-1 indicates no parent)
        
        // Perform BFS
        while (!q.empty()) {
            int node = q.front().first; // Current node being processed
            int parent = q.front().second; // Parent of the current node
            q.pop(); // Remove the node from the queue
            
            // Check all adjacent nodes of the current node
            for (auto adjNode : adj[node]) {
                // If the adjacent node hasn't been visited yet
                if (!vis[adjNode]) {
                    vis[adjNode] = 1; // Mark it as visited
                    q.push({adjNode, node}); // Push it into the queue with the current node as its parent
                }
                // If the adjacent node has been visited and is not the parent of the current node
                else if (adjNode != parent) {
                    return true; // Cycle detected
                }
            }
        }
        return false; // No cycle found in this component
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> adj) {
        int N = adj.size(); // Number of nodes in the graph
        vector<int> vis(N, 0); // Visited array to track visited nodes
        
        // Check each component of the graph
        for (int i = 0; i < N; i++) {
            if (!vis[i]) { // If the node hasn't been visited
                if (bfs(adj, vis, i)) return true; // Perform BFS and check for cycles
            }
        }
        return false; // No cycles found in the entire graph
        // Code here
    }
};

/*
Approach:
- The function uses Breadth-First Search (BFS) to detect cycles in an undirected graph.
- It maintains a visited array to track which nodes have been explored and a queue to manage the BFS.
- When traversing the graph, if it finds an adjacent node that has already been visited and is not the parent of the current node, a cycle is detected.

Time Complexity:
- O(V + E): Each vertex and edge is visited at most once during the BFS traversal, where V is the number of vertices and E is the number of edges.

Space Complexity:
- O(V): The space used by the visited array and the queue (in the worst case, the queue can store all vertices of a component).

Important Points:
- vis[root] = 1: Marks the starting node as visited to prevent revisiting.
- q.push({root, -1}): Initializes the queue with the root node and a parent of -1 (indicating no parent).
- The if condition checking `if (adjNode != parent)` is crucial for cycle detection; it ensures that we do not count the direct back edge to the parent as a cycle.
*/



//2. using DFS

class Solution {
    private:
     // DFS function to detect a cycle in an undirected graph
     bool dfs(vector<vector<int>>& adj, vector<int>& vis, int root, int parent) {
         vis[root] = 1; // Mark the current node as visited
         
         // Traverse all adjacent nodes of the current node
         for (auto adjNode: adj[root]) {
             // If the adjacent node is not visited, do DFS on it
             if (!vis[adjNode]) {
                 // If DFS on the adjacent node finds a cycle, return true
                 if (dfs(adj, vis, adjNode, root)) return true;
             }
             // If the adjacent node is visited and is not the parent of the current node, a cycle is detected
             else if (adjNode != parent) {
                 return true; // Cycle detected
             }
         }
         return false; // No cycle found in this DFS path
     }
  
  public:
    // Function to detect cycle in an undirected graph
    bool isCycle(vector<vector<int>> adj) {
        int N = adj.size(); // Number of nodes in the graph
        vector<int> vis(N, 0); // Visited array to track visited nodes
        
        // Check all components of the graph
        for (int i = 0; i < N; i++) {
            if (!vis[i]) { // If node i is not visited
                // Perform DFS on the unvisited node and check for cycles
                if (dfs(adj, vis, i, -1)) return true; // Start DFS with no parent (-1)
            }
        }
        return false; // No cycles found in any component
    }
};

/*
Approach:
- The function uses Depth-First Search (DFS) to detect cycles in an undirected graph.
- Each node is visited once, and its adjacent nodes are explored recursively.
- If an adjacent node is found to be visited and is not the parent of the current node, a cycle is detected.
- The function traverses each connected component of the graph to ensure no cycles are present in any component.

Time Complexity:
- O(V + E): Each vertex and edge is visited once during DFS. Here, V is the number of vertices and E is the number of edges.

Space Complexity:
- O(V): The space used by the visited array and the recursion stack (in the worst case, the depth of the recursion can go up to V).

Important Points:
1. `vis[root] = 1;`: Marks the current node as visited to prevent revisiting it.
2. `if (!vis[adjNode]) { ... }`: If an adjacent node is unvisited, we call DFS on that node.
3. `else if (adjNode != parent)`: This condition checks for cycles. If an adjacent node is visited and is not the parent of the current node, we have detected a cycle.
4. `dfs(adj, vis, i, -1)`: Starts DFS for each unvisited node, initializing its parent to -1 (no parent for the first call).
*/
