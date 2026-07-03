/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

void leftsub(Node *root,vector<int>&ans)
{   if(!root||(!root->left&&!root->right)) return;
    ans.push_back(root->data);
    if(root->left)
    {
        leftsub(root->left,ans);
    }
    else
    {
        leftsub(root->right,ans);
    }
    return;
}
void nonleaf(Node*root,vector<int>&ans)
{   if(!root ) return;
    if(!root->left&&!root->right)
    {
        ans.push_back(root->data);
        return ;
    }
    
    nonleaf(root->left,ans);
    nonleaf(root->right,ans);
    
}
void rightsub(Node *root,vector<int>&ans)
{  if(!root||(!root->left&&!root->right)) return ;
    if(root->right)
    {
            rightsub(root->right,ans);
    }
    else
    {
        rightsub(root->left,ans);
    }
    ans.push_back(root->data);
    return;
}



class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int>v;
        v.push_back(root->data);
        if(!root->left&&!root->right)
        return v;
        leftsub(root->left,v);
        nonleaf(root,v);
        rightsub(root->right,v);
        return v;
        
    }
};