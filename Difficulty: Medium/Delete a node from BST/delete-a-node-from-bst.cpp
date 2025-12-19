/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node *minValue(Node *root) {
        Node *curr = root;
        while(curr && curr->left) {
            curr = curr->left;
        }
        
        return curr;
    }
  
    Node* delNode(Node* root, int x) {
        
        if(!root) {
            return NULL;
        }
        
        if(x == root->data) {
            // 0 child
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
            // 1 child
            else if(root->left && !root->right) {        // only left child
                Node *temp = root->left;
                delete root;
                return temp;
            } else if(!root->left && root->right) {     // only right child
                Node *temp = root->right;
                delete root;
                return temp;
            } else {        // two child
                Node *temp = minValue(root->right);
                root->data = temp->data;
                root->right = delNode(root->right, temp->data);
            }
        } else if(x > root->data) {    // x > root->data
            root->right = delNode(root->right, x);
        } else {            // x < root->data
            root->left = delNode(root->left, x);
        }
        
        return root;
    }
};