//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int mod = (int)(1e9 + 7);
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    
        // Base case: sum = 0 can always be formed by taking no element
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
    
        // DP computation
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                // Exclude current element
                dp[i][sum] = dp[i - 1][sum];
    
                // Include current element if it's not greater than sum
                if (arr[i - 1] <= sum) {
                    dp[i][sum] += dp[i - 1][sum - arr[i - 1]];
                    
                dp[i][sum]%=mod;
                }
            }
        }
    
        return dp[n][target]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends