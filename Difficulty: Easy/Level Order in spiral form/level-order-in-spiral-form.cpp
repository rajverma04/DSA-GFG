/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        
        queue<Node *>q;
        stack<Node *> st;
        
        q.push(root);
        
        bool dir = 0;       // dir = 0: right to left, dir = 1: left to right
        Node *temp;
        while(!q.empty()) {
            int size = q.size();
            if(dir == 0) {      // traverse right to left
                while(!q.empty()) {     // in while can also use size--
                    temp = q.front();
                    q.pop();
                    
                    if(temp->right) {
                        st.push(temp->right);
                    }
                    if(temp->left) {
                        st.push(temp->left);
                    }
                    ans.push_back(temp->data);
                }
                dir = 1;
            } else {        // dir == 1: traverse left to right
                int size = q.size();
                while(!q.empty()) {         // in while can also use size--
                    temp = q.front();
                    q.pop();
                    
                    if(temp->left) {
                        st.push(temp->left);
                    }
                    if(temp->right) {
                        st.push(temp->right);
                    }
                    ans.push_back(temp->data);
                }
                dir = 0;
            }
            while(!st.empty()) {
                q.push(st.top());
                st.pop();
            }
        }
        
        
        return ans;
    }
};