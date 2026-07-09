class DSU {
    public:
        vector<int> parent;
        vector<int> size;
        
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int node) {
            if(parent[node] == node) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }
        
        void unionSet(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            
            if(pu == pv) {
                return;
            }
            if(size[pu] <  size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

class Solution {
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        
        for(auto e : edges) {
            dsu.unionSet(e[0], e[1]);
        }
        
        int ans = 0;
        for(int i = 0; i < V; i++) {
            if(dsu.find(i) == i) {
                ans++;
            }
        }
        
        return ans;
        
    }
};