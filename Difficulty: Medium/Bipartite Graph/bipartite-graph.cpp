//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int start,vector<int>adj[],vector<int>&color)
    {   queue<int>q;
        q.push(start);
    	color[start]=0;
        while(!q.empty())
	    {
	        int curr=q.front();
	        q.pop();
	        for(auto ele:adj[curr])
	        {
	            if(color[ele]==-1)
	            {
	                color[ele]=(color[curr]+1)%2;
	                q.push(ele);
	            }
	            else
	            {
	                if(color[curr]==color[ele])
	                return false;
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1 && !check(i,adj,color))
	        {
	            return false;
	        }
	    }
	    return true;
	    
	    
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends