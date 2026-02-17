/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            
            mp[col].push_back(node->data);
            
            if(node->left) {
                q.push({node->left, col - 1});
            }
            if(node->right) {
                q.push({node->right, col + 1});
            }
        }
        
        for(auto &it : mp) {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};