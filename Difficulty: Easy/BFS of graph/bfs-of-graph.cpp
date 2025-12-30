class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n, false);
        queue<int> q;
        
        // start bfs from node 0
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto neighbour : adj[node]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};