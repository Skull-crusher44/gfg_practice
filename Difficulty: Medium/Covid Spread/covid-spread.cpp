//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        queue<pair<int,int>>q;
        int rows=hospital.size();
        int cols=hospital[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(hospital[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int timer =0;
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                int row= q.front().first;
                int col = q.front().second;
                q.pop();
                
                if(row > 0 && hospital[row-1][col]==1)
                   {
                       q.push({row-1,col});
                       hospital[row-1][col]=2;
                   }
                if(row < rows-1 && hospital[row+1][col]==1)
                    {
                        q.push({row+1,col});
                        hospital[row+1][col]=2;
                        
                    }
                if(col < cols-1 && hospital[row][col+1]==1)
                    {
                        q.push({row,col+1});
                        hospital[row][col+1]=2;
                    }
                if(col > 0 && hospital[row][col-1]==1)
                    {
                        q.push({row,col-1});
                        hospital[row][col-1]=2;
                    }
            }
            if(!q.empty())
            timer++;
           
        } 
        for(int i=0;i<hospital.size();i++)
            {
                for(auto ele : hospital[i])
                {
                    if(ele==1)
                    return -1; 
                }
            }
            return timer;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends