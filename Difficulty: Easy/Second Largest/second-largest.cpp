//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int second_max=-1;
        int first_max=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>first_max)
            {
                second_max=first_max;
                first_max=arr[i];
            }
            else if(arr[i]<first_max&&arr[i]>second_max)
                second_max=arr[i];
        }
        return second_max;
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
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends