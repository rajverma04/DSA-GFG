class Solution {
  public:
  
    void dfs(int node, vector<vector<pair<int, int>>> &adj, stack<int> &st, vector<int> &vis) {
        vis[node] = 1;
        for(auto [nbr, wt] : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, st, vis);
            }
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);      // {node, wt}
        
        for(auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> vis(V);
        stack<int> st;
        dfs(0, adj, st, vis);
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(auto [nbr, wt] : adj[node]) {
                if(dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                }
            }
        }
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};
