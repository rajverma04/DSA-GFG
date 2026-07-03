/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        
        queue<Node*>q;
        vector<int>v;
        if(!root) return v;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                auto x=q.front();
                q.pop();
                if(i==0)
                v.push_back(x->data);
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
            }
            
        }
        return v;
    }
};