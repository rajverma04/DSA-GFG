/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    int maxSum(Node *root, int &sum) {
        if(!root) {
            return 0;
        }    
        
        // leaf node
        if(!root->left && !root->right) {
            return root->data;
        }
        
        int left = maxSum(root->left, sum);
        int right = maxSum(root->right, sum);
        
        if(root->left && root->right) {
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        } else if(root->left) {
            return root->data + left;
        } else {
            return root->data + right;
        }
        
    }
    
    
    int maxPathSum(Node* root) {
        int sum = INT_MIN;
        
        int val = maxSum(root, sum);
        
        if(root->left && root->right) {
            return sum;
        }
        
        return max(sum, val);
        return sum;
        
    }
};