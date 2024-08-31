//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool heapify(int arr[],int size,int index)
    {
        int largest = index;
        int left=2*index+1;
        int right=2*index+2;
        
        if(left<size&&arr[left]>arr[index])
        return false;
        else if (left<size&&arr[right]>arr[index])
        return false;
        return true;
    }
    bool isMaxHeap(int arr[], int n)
    {
        for(int i= n/2-1;i>=0;i--)
        {
            if(!heapify(arr,n,i))
            {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends