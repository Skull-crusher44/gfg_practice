//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        vector<int>ans(N,-1);
        stack<int>s;
        for(int i=0;(i%N)<N;i++)
        {
           
            while(!s.empty()&&arr[i%N]>arr[s.top()])
            {
                ans[s.top()]=arr[i%N];
                s.pop();
            }
            s.push(i%N);
            if(i==2*N-1)
            break;
        }
        // for(int i=0;i<N;i++)
        // {
           
        //     while(!s.empty()&&arr[i]>arr[s.top()])
        //     {
        //         ans[s.top()]=arr[i];
        //         s.pop();
        //     }
        //     s.push(i);
        // }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends