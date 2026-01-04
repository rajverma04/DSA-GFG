class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, stack<int> &st, vector<bool> &visited) {
        visited[node] = true;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                DFS(it, adj, st, visited);
            }
        }
        
        st.push(node);
    }
    
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> visited(V, false);
        
        // 🔥 STEP 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, adj, st, visited);
            }
        }
        
        
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        
        return ans;
    }
};