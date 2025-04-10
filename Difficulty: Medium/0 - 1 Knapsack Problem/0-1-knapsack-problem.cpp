//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int recursive(vector<int>&wt, vector<int>&val , int w , int n , vector<vector<int>>&memo){
        //Base condition 
        if(n==0||w==0)
        return 0;
        
        //check if already exist in memo
        if(memo[n][w]!=-1)
            return memo[n][w];
            
        int pick=0;
        if(wt[n-1]<=w)
            pick = val[n-1] + recursive(wt,val,w-wt[n-1],n-1,memo);
        
        int notPick = recursive(wt,val,w,n-1,memo);
        
        //store the result in memo array an then return 
        return memo[n][w]=max(pick,notPick);
        
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n= val.size();
        vector<vector<int>>memo(n+1,vector<int>(W+1,-1));
        return recursive(wt,val,W,n,memo);
        
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends