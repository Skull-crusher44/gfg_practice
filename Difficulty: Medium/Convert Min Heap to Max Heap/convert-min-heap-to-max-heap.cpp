//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Heapify(vector<int> &arr,int size,int index)
{
    bool flag = true;
    while(flag){
        // largest will store the index of the largest element among the left and right children of index
        int largest = index;

        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < size && arr[left] > arr[index])
            largest = left;
        if(right < size && arr[right] > arr[largest])
        largest = right;

        //two possibilities    1=> index is greater than both left and right . then largest will have the same index !!!!(ya fir left and right donon exist hi na kare )
        //                     2=> index is smaller than anyone  left or  right , then largest will be updated with  bigggest index among left and right children

        if(largest!=index )
        {
            swap(arr[index], arr[largest]);
            index = largest;
        }
        else{
            flag = false;
        }
    }
}
    void convertMinToMaxHeap(vector<int> &arr, int size){
    //step down approach  (level order traversal form down to up from 1st parent (non leaf node))
    int below_first_parent = size / 2 - 1;
    for (int i = below_first_parent;i>=0;i--)
    {
        Heapify(arr, size, i);
    }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends