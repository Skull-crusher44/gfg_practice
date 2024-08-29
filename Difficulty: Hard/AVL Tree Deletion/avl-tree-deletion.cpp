//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    setHeights(root);
    return root;
}

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

struct Node* deleteNode(struct Node* root, int data);

int main()
{
	int t;
	cin>>t;
	getchar();

	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root = buildTree(s);
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	}
	return 1;
}

// } Driver Code Ends


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/



int getHeight(Node*root)
{
    if(!root)return 0;
    return root->height;
}
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






Node* deleteNode(Node* root, int val)
{
    if(!root)return NULL;

    if(root->data > val)//left side
    root->left = deleteNode(root->left,val);
    else if(root->data < val)//right side 
    root->right = deleteNode(root->right,val);
    else
    {   //Leaf Node 
        if(!root->left&&!root->right)
        {
            delete root;
            return NULL;
        }//only left child exist 
        else if(root->left&&!root->right)
        {
            Node*temp=root->left;
            delete root;
            return temp;
        }//only right child exist
        else if(root->right&&!root->left)
        {
            Node*temp=root->right;
            delete root;
            return temp;
        }//when both exist 
        else{
            
            //rightside smallest node
            Node *curr = root->right;
            while(curr->left)
                curr = curr->left;
            root->data = curr->data;
            root->right=deleteNode(root->right,curr->data);
        }
    }
    //while coming back update height and check balancing 


    root->height = max(getHeight(root->left), getHeight(root->right))+1;

    //Balancing check
    int balance = getbalance(root);

    if(balance>1)
    {
        //left side unbalanced ha 
        if(getbalance(root->left)>=0)                // 85(root)(LL)
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
        if(getbalance(root->right)<=0)                 // 85 (root)(RR)
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