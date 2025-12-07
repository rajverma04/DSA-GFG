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
    // find height of left and right node
    int findHeight(Node *root, int &ans) {
        if(!root) {
            return 0;
        }
        int left = findHeight(root->left, ans);
        int right = findHeight(root->right, ans);
        
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int diameter(Node* root) {
        int ans = 0;
        
        findHeight(root, ans);
        return ans;
        
    }
};