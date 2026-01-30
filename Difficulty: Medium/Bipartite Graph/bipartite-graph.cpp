class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(V, -1);       // -1 : uncolored , {0 : red, 1: blue}
        
       for(int start = 0; start < V; start++) {
           if(color[start] == -1) {
               color[start] = 0;
               queue<int> q;
               q.push(start);
               
               while(!q.empty()) {
                   int node = q.front();
                   q.pop();
                   
                   for(auto nbr : adj[node]) {
                       if(color[nbr] == -1) {       // not colored
                           q.push(nbr);
                           color[nbr] = 1 - color[node];        // assign opposite color to node
                       } else if(color[nbr] == color[node]) {       // same color as node 
                           return false;
                       }
                       
                   }
               }
           }
       }
       
       return true;
    }
};