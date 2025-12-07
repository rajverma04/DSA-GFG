/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node *root, bool &ans) {
        if(!root) {
            return 0;
        }
        
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        
        if(abs(left - right) > 1) {
            ans = 0;
        }
        
        return 1 + max(left, right);
    }
    
    
    bool isBalanced(Node* root) {
        bool ans = true;
        
        height(root, ans);
        return ans;
    }
};