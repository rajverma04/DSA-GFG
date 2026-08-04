class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto e : edges) {
            adj[e[1]].push_back(e[0]);      // reverse the edge direction    
        }
       
        vector<int> inDeg(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                inDeg[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(int nbr : adj[node]) {
                inDeg[nbr]--;
                if(inDeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        
        
        return ans;
        
    }
};