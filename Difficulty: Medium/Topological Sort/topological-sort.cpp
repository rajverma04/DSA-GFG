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
        // 🔥 STEP 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> ans;
        // vector<bool> visited(V, false);
        // stack<int> st;
        
        // for(int i = 0; i < V; i++) {
        //     if(!visited[i]) {
        //         DFS(i, adj, st, visited);
        //     }
        // }
        
        
        
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        
        
        // M2: Kahn's Algo.
        
        vector<int> inDeg(V, 0);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                inDeg[adj[i][j]]++;
            }
        }
        
        // push all node of zero indegree into queue;
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(!inDeg[i]) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i = 0; i < adj[node].size(); i++) {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        
        return ans;
    }
};