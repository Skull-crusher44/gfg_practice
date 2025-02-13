//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        unordered_map<int,int>mp;
        int prefix_sum=0;
        int max_len=0;
        
        for(int i=0;i<arr.size();i++){
            prefix_sum+=arr[i];
            
            if(prefix_sum==0)
            max_len=i+1;
            else if(mp.find(prefix_sum)!=mp.end())
            max_len= max(max_len,i-mp[prefix_sum]);
            
        // we have to take farthest point if prefix_sum(x) multiple baar aya ha pahle ke time me
        //              i
        // aur hme abhi prefix_sum ki same value mili ha to use update nahi karna kyunki agar hame 
        //aage kahi bhi vahi  prefix_sum dobara aya to mp[prefix_sum ] should be pointing to first occurance 
        
            if(mp.find(prefix_sum)==mp.end())
            mp[prefix_sum]=i;
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends