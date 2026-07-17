class Solution {
  public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
        vis[node] = 1;
        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjT) {
        vis[node] = 1;
        for(auto nbr : adjT[node]) {
            if(!vis[nbr]) {
                dfs2(nbr, vis, adjT);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        
        vector<vector<int>> adjT(V);
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfs2(node, vis, adjT);
            }
        }
        
        return scc;
    }
};