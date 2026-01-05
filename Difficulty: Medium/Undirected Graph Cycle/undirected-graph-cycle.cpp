class Solution {
  public:
  
    bool BFS(int node, vector<vector<int>>& adj, vector<bool> &visited) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = true;
        while(!q.empty()) {
            int child = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int i = 0; i < adj[child].size(); i++) {
                if(visited[adj[child][i]] == false) {
                    visited[adj[child][i]] = true;
                    q.push({adj[child][i], child});
                } else {
                    if(adj[child][i] != parent) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool ans = BFS(i, adj, visited);
                if(ans) {
                    return true;
                }
            }
        }
        
        return false;
    }
};