class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int> >> adj(V);     // {node, wt}
        
        for(auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        pq.push({0, src});              // {wt, src}
        
        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(wt > dist[node]) {
                continue;
            }
            
            for(auto [nbr, d] : adj[node]) {
                if(dist[node] + d < dist[nbr]) {
                    dist[nbr] = dist[node] + d;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        
        return dist;
    }   
};