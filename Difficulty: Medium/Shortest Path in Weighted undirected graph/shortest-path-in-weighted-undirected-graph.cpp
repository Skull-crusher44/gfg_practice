//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        //Create adjacency List
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];
            int weight=edges[i][2];
            adj[src].push_back({dest,weight});
            adj[dest].push_back({src,weight});
            
        }
        
        
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>parent(n+1,-1);
        vector<int>dist(n+1,INT_MAX);
        vector<bool>visited(n+1,false);
        
        q.push({0,1});
        dist[1]=0;
        
        while(!q.empty())
        {
            int curr_node=q.top().second;
            q.pop();
            
            if(visited[curr_node])
            continue;
            
            visited[curr_node]=1;
            
            for(auto it:adj[curr_node])
            {
                int neighbour=it.first;
                int weight=it.second;
                if (!visited[neighbour]&&  dist[curr_node] + weight < dist[neighbour] ) 
                {
                    dist[neighbour] = dist[curr_node] + weight;
                    parent[neighbour] = curr_node;
                    // Push the neighbor into the queue with its updated distance
                    q.push({dist[neighbour], neighbour});
                }
            }
        }
        // return cost+path
        
        // if i can't reach destination
        if(parent[n]==-1)
        {
            return {-1};
        }
        //if i can reach destination
        vector<int>path;
        int dest=n;
        while(dest!=-1)
        {
            path.push_back(dest);
            dest=parent[dest];
        }
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends