class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for(int nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};