class Solution {
  public:
    bool DFS(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &path, int node) {
        visited[node] = true;
        path[node] = true;
        
        for(int i = 0; i < adj[node].size(); i++) {
            if(!visited[adj[node][i]]) {     // adjacent node is not visited
                if(DFS(adj, visited, path, adj[node][i])) {
                    return true;
                }
            } else if(path[adj[node][i]]) {        // cycle present   // adjacent node is already visited
                return true;
            }
        }
        
        
        // if there is no cycle present in that route
        path[node] = false;     // backtrack
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(DFS(adj, visited, path, i)) {      // i : node
                    return true;
                }
            }
        }
        
        
        return false;
    }
};