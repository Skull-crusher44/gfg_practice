
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
//solution 1 
//using hashmap<diagonal index,elements of that index>;
void dt(Node*root,map<int,vector<int>>&mp,int l)
{
    if(!root)
    return;
    
    mp[l].push_back(root->data);
    
    //increase left level by 1
    dt(root->left,mp,l+1);
    //don't increase left level by 1
    dt(root->right,mp,l);
}

vector<int> diagonal(Node *root)
{
    map<int,vector<int>>mp;
    vector<int>ans;
    
    dt(root,mp,0);
    for(auto it:mp)
    {
        vector<int>v=it.second;
        for(auto val:v)
        {
            ans.push_back(val);
        }
    }
    return ans;
}

//Solution 2 using coder army logic
void find(Node*root,int pos, int &l)
{
    if(!root)
    return;
    
    l=max(pos,l);
    
    find(root->left,pos+1,l);
    find(root->right,pos,l);
}
void diag_ele(Node*root,int pos,vector<vector<int>>&v)
{
    if(!root)
    return;
    
    //push node->data at corressponding index in ans vector
    v[pos].push_back(root->data);
    
    diag_ele(root->left,pos+1,v);
    diag_ele(root->right,pos,v);
}
vector<int> diagonal(Node *root)
{
   int l =0; 
   find(root,0,l);//position of leftmost diagonal
   vector<vector<int>>v(l+1);
   vector<int>ans;
   diag_ele(root,0,v);
   
   for(int i=0;i<v.size();i++)
   {
       for(int j=0;j<v[i].size();j++)
       ans.push_back(v[i][j]);
   }
   return ans;
}
//geeks for geeks approach
//pahle diagonal no 0 ke sare nodes print kare aur agar koi left node dikhe to queue me push kardo
vector<int> diagonal(Node *root)
{
   
   queue<Node*>q;
   q.push(root);
   vector<int>ans;
   while(!q.empty())
   {
       int size=q.size();
       while(size--)
       {
           Node*temp=q.front();
           q.pop();
           while(temp)
           {
               ans.push_back(temp->data);
               if(temp->left)
               q.push(temp->left);
               temp=temp->right;
           }
       }
   }
   return ans;
}
