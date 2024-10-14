//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int X, int Y) {
         
        if(grid[0][0]==0||grid[X][Y]==0)
        return -1;
        //if size==1 and that value is zero  
        if(X==0&&Y==0)
        return 0;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=-1;

        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int curr_level=q.front().second;
            q.pop();

            vector<pair<int,int>>destination={{-1,0},{0,-1},{0,1},{1,0}};
            for(auto des:destination)
            {
                int row=i+des.first;
                int col=j+des.second;
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1)
                {
                    grid[row][col]=-1;
                    q.push({{row,col},curr_level+1});
                    if(row==X && col==Y)
                    return curr_level;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends