/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    void preorderTraversal(Node *root, vector<int> &ans) {
        if(!root) {
            return;
        }
        ans.push_back(root->data);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        
        preorderTraversal(root, ans);
        return ans;
    }
};