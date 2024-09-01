//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void Heapify(vector<int>&arr,int n,int index)
    {
       
        // largest will store the index of the largest element among the left and right children of index
        int largest = index;

        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
        largest = right;

        //two possibilities    1=> index is greater than both left and right . then largest will have the same index !!!!(ya fir left and right donon exist hi na kare )
        //                     2=> index is smaller than anyone  left or  right , then largest will be updated with  bigggest index among left and right children

        if(largest!=index )
        {
            swap(arr[index], arr[largest]);
           Heapify(arr,n,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        // vector<int>ans;
        // priority_queue<int>q;
        // for(int x:a)
        // q.push(x);
        // for(int x:b)
        // q.push(x);
        // while(!q.empty())
        // {
        //     ans.push_back(q.top());
        //     q.pop();
        // }
        // return ans;
        
        vector<int>arr;
        for(int x:a)
        arr.push_back(x);
        
        for(int x:b)
        arr.push_back(x);
        
        for(int i=arr.size()/2-1;i>=0;i--)
        {
            Heapify(arr,arr.size(),i);
        }
        return arr;
        
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends