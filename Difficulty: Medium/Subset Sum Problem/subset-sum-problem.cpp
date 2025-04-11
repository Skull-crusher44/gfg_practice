//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  //recursive
    bool isSS(vector<int>&arr, int sum, int n){
        if(sum==0)
            return true;
        if(n==0)
            return false;
            
        //if element is greater 
        if(arr[n-1]>sum)
            return isSS(arr,sum,n-1);// then not include in sum 
        else{
            return (isSS(arr,sum-arr[n-1],n-1)||isSS(arr,sum,n-1));//include and not include
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n= arr.size();
        return isSS(arr,sum,n); 
      
        // vector<vector<int>>dp(n+1,vector<int>(sum+1));
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=sum;j++){
        //         if(n==0||sum==0)
        //             dp[i][j]=0;
        //         int pick=0;
        //         if(arr[i-1]==sum)
        //             return true;
        //         else if(arr[i-1]<sum)
        //             pick = arr[i-1]+dp[i-1][sum-arr[i-1]]
        //     }
        // }
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends