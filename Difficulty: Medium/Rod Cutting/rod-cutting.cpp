//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    int maxvalue(vector<int>& price, int length, int index, vector<vector<int>>&memo) {
        // Base case
        if (index == 0 || length == 0)
            return 0;

        if(memo[index][length]!=-1){
            return memo[index][length];
        }
        // If the current piece can be taken
        if (index <= length) {
            return memo[index][length]=max(
                price[index - 1] + maxvalue(price, length - index, index,memo),
                maxvalue(price, length, index - 1,memo)
            );
        } else {
            // Cannot take the current piece
            return memo[index][length] = maxvalue(price, length, index - 1,memo);
        }
    }

    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return maxvalue(price, n, n,memo);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends