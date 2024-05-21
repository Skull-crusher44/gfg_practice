//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
   
class Solution{
  public:
  Node*merge(Node*list1,Node*list2)
    {
        Node*tail=new Node(0);
        Node*head=tail;
        while(list1&&list2)
        {
            if(list1->data<=list2->data)
            {
                tail->next=list1;
                list1=list1->next;
                tail=tail->next;
            }
            else
            {
                tail->next=list2;
                list2=list2->next;
                tail=tail->next;
            }
        }
        if(list1)
        {
            tail->next=list1;   
        }
        if(list2)
        {
            tail->next=list2;
        }
        return head->next;
    }
    Node*mergesort(Node*arr[],int p,int q)
    {
         if (p==q)
        return arr[p];
        
        int mid=(p+q)/2;
        arr[p]=mergesort(arr,p,mid);
        arr[mid+1]=mergesort(arr,mid+1,q);
        arr[p]=merge(arr[p],arr[mid+1]);
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
       return mergesort(arr,0,K-1);
        
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends
