//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
     bool check(Node* root)
    {
        // Base case: If the node is null, it satisfies the sum property by definition
        if (!root) return true;
        
        // Base case: If the node is a leaf (no children), it satisfies the sum property
        if (!root->left && !root->right) return true;
        
        // Recursively check the left and right subtrees
        bool left = check(root->left);
        bool right = check(root->right);
        
        // Get the value of the left child, or 0 if there is no left child
        int left_val = (root->left) ? root->left->data : 0;
        
        // Get the value of the right child, or 0 if there is no right child
        int right_val = (root->right) ? root->right->data : 0;
        
        // Check if the current node's value is equal to the sum of its children's values
        bool root_check = false;
        if (root->data == (left_val + right_val))
            root_check = true;
        
        // Return true if both subtrees satisfy the sum property and the current node satisfies it as well
        return (left && right && root_check);
    }
    
    int isSumProperty(Node* root)
    {
        return check(root);
    }
/*
Stepwise Algorithm
Base Cases:

If the current node (root) is nullptr, return true.
If the current node is a leaf (no left or right children), return true.
Recursive Checks:

Recursively call the check function on the left child (root->left).
Recursively call the check function on the right child (root->right).
Value Retrieval:

If the left child exists, store its value in left_val, otherwise set left_val to 0.
If the right child exists, store its value in right_val, otherwise set right_val to 0.
Current Node Check:

Check if the current node's value is equal to the sum of left_val and right_val.
Store the result of this check in root_check.
Return Result:

Return true if both the left and right subtrees satisfy the sum property and the current node satisfies the sum property (left && right && root_check).
Wrapper Function:

Call the check function with the root of the tree and return its result.*/
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumProperty(root) << endl;
    }
    return 0;
}

// } Driver Code Ends