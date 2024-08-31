//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<k;i++)
        {
            q.push(arr[i]);
            
        }
        vector<int>ans(n,-1);
        ans[k-1]=q.top();
       for(int i=k;i<n;i++)
       {
           if(arr[i]>q.top())
           {
               ans[i]=q.top();
               q.pop();
               q.push(arr[i]);
           }
           ans[i]=q.top();
       }
       return ans;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends