//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int curr, vector<pair<int,int>>adj[], vector<int>&ans, vector<bool>&visited)
  {
      visited[curr]=true;
        for(auto it : adj[curr])
            {
                int ele=it.first;
                int weight=it.second;
                if(!visited[ele])
                {
                    ans[ele]=ans[curr]+weight;
                    dfs(ele,adj,ans,visited);
                }
                else
                {
                    if(ans[curr]+weight < ans[ele])
                    {
                        ans[ele]= ans[curr]+weight;
                        dfs(ele,adj,ans,visited);
                    }
                }
            }
            
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
        
        vector<int>ans(N,-1);
        vector<bool>visited(N,0);
        //Apply dfs
       
        ans[0]=0;
        dfs(0,adj,ans,visited);
        return ans;
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