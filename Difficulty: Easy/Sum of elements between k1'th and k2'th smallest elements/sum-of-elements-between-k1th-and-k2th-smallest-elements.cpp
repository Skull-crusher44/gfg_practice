//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long> max_h1;
        priority_queue<long long> max_h2;
        
        for(long long i=0; i < N;i++){
            max_h1.push(A[i]);
            max_h2.push(A[i]);
            
            if(max_h1.size() > K1)
                max_h1.pop();
            if(max_h2.size() > K2)
                max_h2.pop();
            
        }
        
        max_h2.pop();
        long long ans = 0;
        while(max_h2.top() != max_h1.top()){
            ans+=max_h2.top();
            max_h2.pop();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends