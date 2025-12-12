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
    // left subtree except leaf
    void leftSubtree(Node *root, vector<int> &ans) {
        if(!root || (!root->left && !root->right)) {
            return;
        }
        
        ans.push_back(root->data);
        if(root->left) {
            leftSubtree(root->left, ans);
        } else {
            leftSubtree(root->right, ans);
        }
        
        return;
    }
    
    // leaf node
    void leafNode(Node *root, vector<int> &ans) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        
        leafNode(root->left, ans);
        leafNode(root->right, ans);
    }
    
    // reverse right sub tree except leaf
    void rightSubtree(Node *root, vector<int> &ans) {
        if(!root || (!root->left && !root->right)) {
            return;
        }
        
        if(root->right) {
            rightSubtree(root->right, ans);
        } else {
            rightSubtree(root->left, ans);
        }
        
        ans.push_back(root->data);
        return;
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        ans.push_back(root->data);
        
        if(!root->left && !root->right) {
            return ans;
        }
        leftSubtree(root->left, ans);
        leafNode(root, ans);
        rightSubtree(root->right, ans);
        
        return ans;
    }
};