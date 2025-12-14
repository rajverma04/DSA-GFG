// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node *Find(int pre[], int min, int max, int &index, int size) {
        if(index >= size || pre[index] > max) {
            return NULL;
        }
        
        Node *root = new Node;
        root->data = pre[index];
        index++;
        
        root->left = Find(pre, min, root->data, index, size);
        root->right = Find(pre, root->data, max, index, size);
        
        return root;
    }
    
    
    Node* Bst(int pre[], int size) {
        int min = INT_MIN, max = INT_MAX, index = 0;
        
        return Find(pre, min, max, index, size);
        
    }
};