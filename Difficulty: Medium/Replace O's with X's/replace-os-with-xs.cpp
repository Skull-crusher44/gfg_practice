//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i,int j, int n, int m, vector<vector<char>>&mat)
    {
        mat[i][j]='T';
        // traverse through neighbour in four directions
        int roo[]={-1,0,0,1};
        int coo[]={0,-1,1,0};
        
        for(int k=0;k<4;k++)
        {
            int row=i+roo[k];
            int col=j+coo[k];
            if(row>=0 && row<n && col>=0 && col<m && mat[row][col]=='O')
            {
                dfs(row,col,n,m,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        //first row
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O')
            {
                dfs(0,j,n,m,mat);
            }
        }
        //last row
        for(int j=0;j<m;j++)
        {
            if(mat[n-1][j]=='O')
            {
                dfs(n-1,j,n,m,mat);
            }
        }
        //first column
        for(int i=1;i<n-1;i++)
        {
            if(mat[i][0]=='O')
            {
                dfs(i,0,n,m,mat);
            }
        }
        //last column
        for(int i=1;i<n-1;i++)
        {
            if(mat[i][m-1]=='O')
            {
                dfs(i,m-1,n,m,mat);
            }
        }
        // replace 'O'to 'X' and 'T'to'O'
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O')
                mat[i][j]='X';
                else if(mat[i][j]=='T')
                mat[i][j]='O';
            }
        }
        return mat;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends