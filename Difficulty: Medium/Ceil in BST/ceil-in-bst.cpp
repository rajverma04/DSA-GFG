class Solution {
  public:
    int findCeil(Node* root, int x) {
        if(!root) {
            return -1;
        }
        
        if(root->data == x) {
            return root->data;
        }
        
        if(root->data < x) {
            return findCeil(root->right, x);
        }
        
        int leftCeil = findCeil(root->left, x);
        
        return (leftCeil >= 0 && leftCeil != 0) ? leftCeil : root->data;
    }
};
