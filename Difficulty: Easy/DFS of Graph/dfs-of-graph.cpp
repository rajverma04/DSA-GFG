class Solution {
  public:
  
    void DFS(int node, vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited) {
        // if(visited[node]) {
        //     return;
        // }
        
        visited[node] = true;
        ans.push_back(node);
        
        for(auto neighbour : adj[node]) {
            if(!visited[neighbour]) {
                DFS(neighbour, adj, ans, visited);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        
        DFS(0, adj, ans, visited);
        
        return ans;
        
    }
};