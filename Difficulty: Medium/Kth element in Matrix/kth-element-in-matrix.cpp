//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

void Heapify(vector<int>&arr,int size,int index)
{
    int smallest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<size && arr[left] < arr[smallest])
    smallest=left;
    if(right<size && arr[right] < arr[smallest])
    smallest=right;
    
    if(smallest!=index)
    {
        swap(arr[smallest],arr[index]);
        Heapify(arr,size,smallest);
    }
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0 ;j<n;j++)
        {
           arr.push_back(mat[i][j]); 
        }
    }
    
    int size=arr.size();
    
    for(int i=size/2-1;i>=0;i--)
    {
        Heapify(arr,arr.size(),i);
    }
    
    
    int val=-1;
    for(int i=0;i<k;i++)
    {
         val=arr[0];
        arr[0]=arr[size-1];
        size--;
        Heapify(arr,size,0);
    }
    return val;
}
