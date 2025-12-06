/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorderTraversal(Node *root, vector<int> &ans) {
        if(!root) {
            return;
        }
        inorderTraversal(root->left, ans);
        ans.push_back(root->data);
        inorderTraversal(root->right, ans);
    }
    
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        
        inorderTraversal(root, ans);
        return ans;
    }
};