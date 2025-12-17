/*
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

class Solution {
  public:
    void find(Node *root, int &prev, bool &ans) {
        if(!root || !ans) {
            return;
        }
        
        
        // preorder
        
        // left side
        find(root->left, prev, ans);
        
        // middle node
        if(prev >= root->data) {
            ans = 0;
            return;
        }
        
        prev = root->data;
        
        // right side
        find(root->right, prev, ans);
    }
  
    bool isBST(Node* root) {
        bool ans = 1;
        int prev = INT_MIN;
        
        find(root, prev, ans);
        
        return ans;
        
    }
};