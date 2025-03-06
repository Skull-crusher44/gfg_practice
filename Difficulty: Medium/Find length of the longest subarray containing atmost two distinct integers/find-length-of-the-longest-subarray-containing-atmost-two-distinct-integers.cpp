//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int totalElements(vector<int>& arr) {
        int left = 0, right = 0, max_len = 0;
        unordered_map<int, int> mp; // stores frequency, not index

        while (right < arr.size()) {
            mp[arr[right]]++; // add arr[right] to window

            // Shrink window if we have more than 2 distinct elements
            while (mp.size() > 2) {
                mp[arr[left]]--;
                if (mp[arr[left]] == 0) {
                    mp.erase(arr[left]);
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends