/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        if(!root) {
            return false;
        }
        if(root->data == key) {
            return true;
        }
        
        if(key > root->data) {
            return search(root->right, key);
        }
        
        if(key < root->data) {
            return search(root->left, key);
        }
        
        
    }
};