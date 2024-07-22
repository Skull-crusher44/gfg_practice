
//soultion 1 
/*
Take a queue.
Start traversing in Level Order Fashion. 
Take every node from queue and check if it is the first node of that level , if yes, then store this in resultant array.
Also store left and right child for each processed node of queue.
*/

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int>ans;
    queue<Node*>q;
    if(!root)return {};
    
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node*curr=q.front();
            if(i==0)
            ans.push_back(curr->data);
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    return ans;
}

//soultion 2 
void left(Node *root,vector<int>&ans,int level)
{
    if(!root)return;
    
    if(level==ans.size()) // if I increasing the level it means we are adding node in ans. if level == ans.size() this means curr node is first node at that level
    ans.push_back(root->data);
    
    left(root->left,ans,level+1);
    left(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   left(root,ans,0);
    return ans;
}

//solution 3

/*
The idea is to use recursion. We can traverse the tree in a preorder manner and maintain the maximum level visited till the current node. 
If the current level is more than the maximum level visited till now, then the current node is the first node of the current level, 
and we print it and max_level will be changed to the current level.
*/

//Function to get the left view of the binary tree.
void leftViewUtil(vector<int>&vec,struct Node *root, int level,int *max_level)
{
    //if root is null, we simply return.
    if (root==NULL)  return;
    
    //if this is the first node of its level then it is in the left view.
    if (*max_level < level)
    {
        //storing data of current node in list.
        vec.push_back(root->data);
        *max_level = level;
    }
    
    //calling function recursively for left and right subtrees of current node. 
    leftViewUtil(vec,root->left, level+1, max_level);
    leftViewUtil(vec,root->right, level+1, max_level);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(struct Node *root)
{
    int max_level = 0;
    vector<int> vec;
    leftViewUtil(vec,root, 1, &max_level);
    //returning the list.
    return vec;
}


