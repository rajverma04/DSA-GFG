class Solution {
  public:
    bool isPossible(int n, vector<pair<int, int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto it : pre) {
            adj[it.second].push_back(it.first);
        }
        
        vector<int> inDeg(n);
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                inDeg[it]++;
            }
        }
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto nbr : adj[node]) {
                inDeg[nbr]--;
                if(inDeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        return count == n;
    }
};