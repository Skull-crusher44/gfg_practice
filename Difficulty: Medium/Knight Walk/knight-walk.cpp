//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	  
	  KnightPos[0]--;
	  KnightPos[1]--;
	  TargetPos[0]--;
	  TargetPos[1]--;
	  //base case  if source pos == dest pos 
	  if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1])
	  return 0;
	  
        queue<pair<pair<int,int>,int>>q; // row,col,curr_dist
        q.push({{KnightPos[0],KnightPos[1]},0});

        vector<vector<int>>grid(N,vector<int>(N,-1));
        grid[KnightPos[0]][KnightPos[1]]==1;
        
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int curr_dist=q.front().second;
            q.pop();
            
            if(i==TargetPos[0] && j==TargetPos[1])
                return curr_dist;
                
            vector<pair<int,int>>destination={{-1,-2},{-1,2},{-2,-1},{-2,1},{1,-2},{1,2},{2,-1},{2,1}};
            for(auto des:destination)
            {
                int row=i+des.first;
                int col=j+des.second;
                if(row>=0 && row<N && col>=0 && col<N && grid[row][col]==-1)
                {
                    grid[row][col]=1;
                    q.push({{row,col},curr_dist+1});
                    
                }
            }
        }
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends