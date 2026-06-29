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
    
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        map<int, int> mp;
        
        queue<tuple<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            
            if(mp.find(col) == mp.end()) {
                mp[col] = node->data;    
            }
            
            if(node->left) {
                q.push({node->left, col - 1});
            }
            if(node->right) {
                q.push({node->right, col + 1});
            }
        }
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};