//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    
    //to get height 
    int getHeight(Node*root)
    {
        if(!root)return 0;
        return root->height;
    }
    
    // get difference 
    int getbalance(Node*root)
    {
        return getHeight(root->left)-getHeight(root->right);
    }

    //left rotation (RR)
    Node* left_rotation(Node* root)
    {
        Node* child = root->right;
        Node*childleft=child->left;
        child->left=root;
        root->right = childleft;
    
        //update the height
        root->height = 1+max(getHeight(root->left), getHeight(root->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    
        return child;
    }

    //right rotaion (LL)
    Node*right_rotation(Node*root)
    {
        Node *child = root->left;
        Node*childright=child->right;
        child->right=root; 
        root->left = childright;
    
        //update the height
        root->height = 1+max(getHeight(root->left), getHeight(root->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    
        return child;
    }
    
    
    Node* insertToAVL(Node* root, int data)
    {
          //if not exist 
        if(!root)return new Node(data);

    //if exist 
    if(data < root->data)
    root->left=insertToAVL(root->left,data);
    else if(data > root->data)
    root->right=insertToAVL(root->right,data);
    else
        return root;  // duplicates elements are not allowed 
    //after inserting node while traversing back we update the height and check for unbalancing in tree 
    //update height
    root->height = max(getHeight(root->left), getHeight(root->right))+1;

    //Balancing check
    int balance = getbalance(root);

    if(balance>1)
    {
        //left side unbalanced ha 
        if(root->left->data > data)                // 85(root)(LL)
        {                                  //83
            return right_rotation(root);       //81
            
        }
        else //(LR)
        {
            root->left=left_rotation(root->left);            //85 (root)(LR)
            return right_rotation(root);                        //83
        }                                                    //82
        
    }
    if(balance<-1)
    {
        //right side unbalanced ha 
        if(root->right->data < data)                 // 85 (root)(RR)
        {                                               //89
            return left_rotation(root);                       //90
            
        }
        else//(RL)
        {                                                   //85(root)(RL)
            root->right=right_rotation(root->right);                 //86
            return left_rotation(root);                             //89
        }
        
    }
    return root;  // when no  balancing is required 
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends