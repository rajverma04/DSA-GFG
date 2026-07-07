class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<bool> &vis, vector<int> &ans) {
        if(vis[node]) {
            return;
        }
        vis[node] = true;
        ans.push_back(node);
        
        for(int nbr : adj[node]) {
            DFS(nbr, adj, vis, ans);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        vector<int> ans;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                DFS(i, adj, vis, ans);
            }
        }
        
        return ans;
    }
};