//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //using bfs
    bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (auto i : adj[node]) {
            if (i == parent) {
                continue;  // Ignore the parent node
            }
            if (visited[i]) {
                return true;  // Cycle detected
            } else {
                if (dfs(i, node, adj, visited)) {
                    return true;  // Cycle found in the recursion
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        // Visit all unvisited nodes (in case of disconnected components)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) {
                    return true;  // Cycle found
                }
            }
        }
        return false;  // No cycle found
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends