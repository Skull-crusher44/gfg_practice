//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int solve(Node*root,int &sum)
    {
        if(!root)return 0;
        
        if(!root->left&&!root->right)
        return root->data;
        
        int left=solve(root->left,sum);
        int right=solve(root->right,sum);
        
        // update tabhi karna ha jab root ke left and right dono exist karte hoon
        if(root->left&&root->right)
        {
            sum= max(sum,left+right+root->data);
            return max(left,right)+root->data;
        }
        //AGAR LEFT EXIST KARE TO LEFT KA MAX SUM +ROOT->DATA RETURN KARO                                                  7
        if(root->left)                          //     7      
        {                                       //       8 MAX(-9,0)+8 => 8 (JO KI WRONG HA)
            return root->data+left;             //    -9
        }
        if(root->right)
        {
            return root->data+right;
        }
    }
    int maxPathSum(Node* root)
    {
        int sum=INT_MIN;
        int val= solve(root,sum);
        
        if(root->left&&root->right)
        return sum;
        // IF ROOT KA YA TO LEFT TREE TA RIGHT TREE HO TO SUM=int_min(KOI UPDATION NAHI HOGA 
        // JABKI VAL ME (FUNCTION RETURN KAREGA USME ) KOI VALUE AAYEGE TO HAME DONO ME MAX RETURN KARNA HA 
        return max(sum,val);
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends