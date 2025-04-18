//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int dp[1001][1001];  // memo table
    int maxi = 0;

    int lcs(int i, int j, const string& s1, const string& s2) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);
            maxi = max(maxi, dp[i][j]);
        } else {
            dp[i][j] = 0;  // not part of a common substring
        }

        // Call lcs on all pairs to ensure we explore all starting points
        lcs(i - 1, j, s1, s2);
        lcs(i, j - 1, s1, s2);

        return dp[i][j];
    }
    int longestCommonSubstr(string& s1, string& s2) {
       memset(dp, -1, sizeof(dp));
        int m = s1.length();
        int n = s2.length();
        lcs(m - 1, n - 1, s1, s2);
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends