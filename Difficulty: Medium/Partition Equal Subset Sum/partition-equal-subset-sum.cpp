//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(num:arr)sum+=num;
        if(sum&1)return false;
        sum=sum/2;
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
                else if(arr[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends