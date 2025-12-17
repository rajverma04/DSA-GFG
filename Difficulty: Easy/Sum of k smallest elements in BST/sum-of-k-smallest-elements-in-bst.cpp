// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void find(Node *root, int &k, int &sum) {
    if(!root || k < 0) {
        return;
    }
    
    find(root->left, k, sum);
    k--;
    
    if(k >= 0) {
        sum += root->data;
    }
    
    find(root->right, k, sum);
}


int sum(Node* root, int k) {

    int sum = 0;
    find(root, k, sum);
    
    return sum;
    
}