//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
//     int arr1[] = {1, 2, 2, 3};
//      int arr2[] = {2, 3, 4, 5};
//       int n = 4, m = 4;
   
   vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    
    int i = 0, j = 0;
    
    while(i < n && j < m)
    {
        // Skip duplicates in arr1
        if(i > 0 && arr1[i] == arr1[i-1])
        {
            i++;
            continue;
        }
        
        // Skip duplicates in arr2
        if(j > 0 && arr2[j] == arr2[j-1])
        {
            j++;
            continue;
        }
        
        if(arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            ans.push_back(arr2[j]);
            j++;
        }
        else  // if both are equal, add only one
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    // Add remaining elements from arr1
    while(i < n)
    {
        // Skip duplicates
        if(i > 0 && arr1[i] != arr1[i-1])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    
    // Add remaining elements from arr2
    while(j < m)
    {
        // Skip duplicates
        if(j > 0 && arr2[j] != arr2[j-1])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    
    return ans;
}

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends