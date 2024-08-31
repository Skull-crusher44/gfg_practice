//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    void Heapify(vector<int> &arr,int &size,int index)
    {
        bool flag = true;
        while(flag){
            // largest will store the index of the largest element among the left and right children of index
            int largest = index;
    
            int left = index * 2 + 1;
            int right = index * 2 + 2;
    
            if (left < size && arr[left] < arr[index])
                largest = left;
            if(right < size && arr[right] < arr[largest])
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
        int delete_element(vector<int>&arr,int &size){
            int deleted_ele=arr[0];
            arr[0] = arr[size-1];
            size--;
            Heapify(arr,size,0);
            return deleted_ele;
        }
    
    int kthSmallest(vector<int> &arr, int k) 
    {
     //step down approach  (level order traversal form down to up from 1st parent (non leaf node))
        int size=arr.size();
        int below_first_parent = size / 2 - 1;
        for (int i = below_first_parent;i>=0;i--)
        {
            Heapify(arr, size, i);
        }
        
        int ans=0;
        for(int i=0;i<k;i++)
        {
             ans=delete_element(arr,size);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends