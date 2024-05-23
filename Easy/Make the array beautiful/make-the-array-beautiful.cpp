//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        if(arr.size()==1)
        return arr;
        stack<int>s;
        s.push(arr[0]);
        vector<int>v;
        for(int i=1;i<arr.size();i++)
        {
            if(s.empty())
            {
                s.push(arr[i]);
                
            }
            else if((s.top()>=0&&arr[i]>=0)||(s.top()<0&&arr[i]<0))
            {
                s.push(arr[i]);
            }
            else
            s.pop();
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends