//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool>visited(V,0);
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        int curr=S;
        
        for(int i=0;i<V;i++)
        {        
            visited[curr]=true;
            //update the neighbour nodes
            for(auto v:adj[curr])
            {
                int neighbour=v[0];
                int weight=v[1];
                //relax unvisited node 
                if(!visited[neighbour])
                {
                    dist[neighbour]=min(dist[neighbour],dist[curr]+weight);
                    
                }
            }
            //find the min unvisted node 
            int min_among=INT_MAX;
            int min_node=curr;
            for(int i=0;i<dist.size();i++)
            {
                if(!visited[i]&&dist[i]<min_among)
                   {
                       min_among=dist[i];
                        min_node=i;
                       
                   }
            }
            curr=min_node;
        }
        //Convert INT_MAX to -1
        for(int i=0;i<V;i++)
        {
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends