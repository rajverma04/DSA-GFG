/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    int minDiff(Node *root, int K) {
        if(!root) {
            return INT_MAX;
        }
        
        if(K == root->data) {
            return 0;
        } else if(K > root->data) {
            return min(K - root->data, minDiff(root->right, K));
        } else {
            return min(root->data - K, minDiff(root->left, K));
        }
        
    }
};