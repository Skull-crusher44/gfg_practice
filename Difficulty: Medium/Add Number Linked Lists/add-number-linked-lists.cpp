//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node*reverse(Node*head)
    {
        Node*curr=head,*prev=NULL,*Next=head;
        while(curr)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
        
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node*curr1=num1,*curr2=num2;
        int sum,carry=0;

        Node*head=new Node(0);
        Node *tail=head;
        
        while(curr1&&curr2)
        {
            sum = curr1->data + curr2->data + carry;
            
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr1=curr1->next;
            curr2=curr2->next;
            carry = sum/10;
        }
        while(curr1)
        {
            sum = curr1->data + carry;
            
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr1=curr1->next; 
            carry = sum/10;  
        
        }
        while(curr2)
        {
            sum = curr2->data + carry;
            
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr2=curr2->next;
            carry=sum/10;
        }
        while(carry)
        {
            tail->next=new Node(carry%10);
            tail=tail->next;
            carry=carry/10;
        }
        head= reverse(head->next);
        
        // num1 = 045, num2=00054 sum should be 99 but we get  head = 00099
        // jab tak leading zeroes ha  aur data exist karta ha tab tak head aage bdha do
        while(head!=NULL&&head->data==0) 
        {
            head=head->next;
        }
        // num1=000, num2=000 => head = 000;
        // yha par leading zeroes remove karte karte head NULL ko point karega isliye hme return zero karna ha 
        if(head==NULL)
        {
            head=new Node(0);
        }
        return head;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends