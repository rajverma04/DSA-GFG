class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        vector<bool> vis(adj.size(), false);
        queue<int> q;
        
        q.push(0);
        vis[0] = true;
        
        
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};