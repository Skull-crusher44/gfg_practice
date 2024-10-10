//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // Perform BFS to visit all connected components
    int bfs(vector<vector<int>>& mat, int n, int node, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int j = 0; j < n; j++) {
                if (!visited[j] && mat[curr][j] == 1) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return 1;
    }

    int numProvinces(vector<vector<int>> adj, int V) {
         
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(adj, V, i, visited);  // Use BFS to explore the connected components
                count++;
            }
        }
        return count;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends