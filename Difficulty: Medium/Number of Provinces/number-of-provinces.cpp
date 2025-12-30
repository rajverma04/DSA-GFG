// User function Template for C++

class Solution {
  public:
  
    void DFS(vector<vector<int>> &adj, vector<bool> &visited, int node) {
        if(visited[node]) {
            return;
        }
        
        visited[node] = true;
        for(int i = 0; i < adj[node].size(); i++) {
            if(adj[node][i]) {
                DFS(adj, visited, i);
            }
        }
        
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int count = 0;
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                count++;
                DFS(adj, visited, i);
            }
        }
        return count;
    }
};