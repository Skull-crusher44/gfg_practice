//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string canFinish(int n, int V, vector<int>adj[])
    {
        vector<int> indegree(V, 0);
        queue<int> q;
    
        // Calculate indegree for each vertex
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
    
        // Add vertices with indegree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    
       string ans;
    
        // Perform BFS and check for cycles
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans+=char(front +'a');
    
            for (auto it : adj[front]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    
        // If the number of vertices traversed during BFS is not equal to the total number of vertices,
        // then there is a cycle in the graph.
        if (ans.size() == V) {
            return ans; // No cycle
        }
        return ""; // Cycle is present
    }
    
    string findOrder(string dict[], int n, int k) {
       vector<int>adj[k];
       
       for(int k=0;k<n-1;k++)
       {
           string s=dict[k];
           string t=dict[k+1];
           
           int i=0,j=0;
           while(i<s.length() && j<t.length())
           {
               if(s[i]!=t[j])
               {
                   adj[s[i]-'a'].push_back(t[j]-'a');
                   break;
               }
               i++;
               j++;
           }
       }
       return canFinish(n, k, adj);
       
        
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends