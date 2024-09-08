//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){

        vector<int>ans(N);
        unordered_map<int,int>mp;
        
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<N;i++)
        {
            q.push({arr[i],i});
            mp[arr[i]]++;
        }
        int count=1;
        while(!q.empty())
        {
            int value=q.top().first;
            int index=q.top().second;
            q.pop();
            
            if(mp[arr[index]]!=1)
            {
                ans[index]=count;
                mp[arr[index]]--;
            }
            else
            {
                ans[index]=count++;
            }
        }
        return ans;
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
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends