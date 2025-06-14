/*

Definition for Binary Tree Node
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
    void path(Node*root,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(!root)return;
        
        temp.push_back(root->data);
        
        if(!root->left&&!root->right)
        {
            ans.push_back(temp);
        }
       
            path(root->left,ans,temp);
            path(root->right,ans,temp);
            

        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        path(root,ans,temp);
        return ans;
    }
};

