//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int index=-1;
        for(int i=0;i<n;i++)
        {
            bool flag =true;
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    flag=false;
                    break;
                    
                }
            }
            if(flag)
            { 
                index=i;
                break;
            }
        }
        if(index==-1)
        return -1;
        
        for(int i=0;i<n;i++)
        {
            if(M[i][index]==0&&i!=index)
            return -1;
        }
        return index;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends