//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>leftside;
    priority_queue< int, vector<int> ,greater<int> >rightside;
    
    void insertHeap(int &x)
    {
        if(leftside.size()==0)
        {
            leftside.push(x);
            return;
        }
        
        if(x<=leftside.top())
        {
            leftside.push(x);
        }
        else
        {
            rightside.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        //  minheap size (rightside)  should not be greater than maxheap size (leftside)
        if(rightside.size()>leftside.size())
        {
            leftside.push(rightside.top());
            rightside.pop();
        }
        //left and rightside me difference 1 se jyada nhi hona chahiye 
        else if (rightside.size()+1<leftside.size())
        {
            rightside.push(leftside.top());
            leftside.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        // left>right
        if(leftside.size()>rightside.size())
        return leftside.top();
        else
        {
            double ans = (leftside.top()+rightside.top())/2;
            return ans ;
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends