//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, int V, vector<int>adj[], vector<bool>&path, vector<bool>&visited)
    {
        path[node]=true;
        visited[node]=true;
        
        for(auto ele:adj[node])
        {
            if(!visited[ele])
            {
                if(dfs(ele,V,adj,path,visited))
                return true;
            }
            else if(path[ele])
            return true;
        }
        
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i]&&dfs(i,V,adj,path,visited))
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends