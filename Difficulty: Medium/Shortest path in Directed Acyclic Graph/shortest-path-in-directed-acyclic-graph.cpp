//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int curr, vector<pair<int,int>>adj[], vector<bool>&visited,stack<int>&s)
   {
      visited[curr]=true;
        for(auto it : adj[curr])
            {
                int ele=it.first;
                int weight=it.second;
                if(!visited[ele])
                {
                    dfs(ele,adj,visited,s);
                }
            }
        s.push(curr);
            
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //make adjacency List 
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            int src=edges[i][0];
            int des=edges[i][1];
            int weight=edges[i][2];
            
            adj[src].push_back({des,weight});
        }
        
        vector<int>dist(N,INT_MAX);
        vector<bool>visited(N,0);
        stack<int>s;
        //Apply dfs to get topological sort vector
       
        dist[0]=0;
        dfs(0,adj,visited,s);
        
        
        //empty the stack and relax the neighbours 
        while(!s.empty())
        {
            int curr=s.top();
            s.pop();
            for(auto it : adj[curr])
            {
                int ele=it.first;
                int weight=it.second;
                //Relax the neighbour
                dist[ele]=min(dist[ele],dist[curr]+weight);
            }
        }
        //convert INT_MAX to -1
        for(int i=0;i<N;i++)
        {
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends