// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        queue<Node*> q;
        vector<int> ans;
        if(!root) {
            return ans;
        }
        
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;
            
            for(int i = 0; i < size; i++) {
                Node *node = q.front();
                q.pop();
                
                maxi = max(maxi, node->data);
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            
            ans.push_back(maxi);
        }
        
        
        return ans;
        
    }
};