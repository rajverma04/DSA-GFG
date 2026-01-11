class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];       // weight
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<     // {weight, node} : as MST not required in this so not storing parent
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
            > pq;
        vector<bool> visited(V, false);
        pq.push({0,0});     // initial start: {weight, node}
        int sum = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(visited[node]) {     // node already visited
                continue;
            }
            
            visited[node] = true;       // not visited then mark visited
            
            sum += wt;
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int adjW = it[1];
                
                if(!visited[adjNode]) {
                    pq.push({adjW, adjNode});
                }
            }
        }
        
        return sum;
    }
};