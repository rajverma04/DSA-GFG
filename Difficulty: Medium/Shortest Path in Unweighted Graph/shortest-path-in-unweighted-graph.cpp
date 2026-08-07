class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist(V, INT_MAX);
        
        queue<int> q;
        
        dist[src] = 0;
        
        q.push(src);
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            for(auto nbr : adj[node]) {
                if(dist[node] + 1 < dist[nbr]) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }    
            }
        }
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist[dest];
    }
};
