/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*, vector<Node*>> graph;
    Node *startNode = NULL;
    
    void buildTree(Node* root, int target) {
        if(!root) {
            return;
        }
        if(root->data == target) {
            startNode = root;
        }
        
        if(root->left) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            
            buildTree(root->left, target);
        }
        
        if(root->right) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            
            buildTree(root->right, target);
        }
    }
    int minTime(Node* root, int target) {
        buildTree(root, target);
        
        unordered_set<Node*> vis;
        queue<Node*> q;
        q.push(startNode);
        vis.insert(startNode);
        
        int ans = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto node = q.front();
                q.pop();
                
                for(auto nbr : graph[node]) {
                    if(vis.find(nbr) == vis.end()) {
                        vis.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
            ans++;
        }
        
        return ans;
    }
};