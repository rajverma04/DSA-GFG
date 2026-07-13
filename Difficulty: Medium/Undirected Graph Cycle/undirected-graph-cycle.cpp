class Solution {
  public:
    vector<int> parent, size;
    int find(int node) {
        if(parent[node] == node) {
            return node;
        }
        
        return parent[node] = find(parent[node]);
    }
    
    bool unionSet(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) {
            return true;
        }
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        size.resize(V, 1);
        
        iota(parent.begin(), parent.end(), 0);          // it will the vector from 0 to v - 1(sequentially)
        
        for(auto e : edges) {
            if(!unionSet(e[0], e[1])) {
                unionSet(e[0], e[1]);
            } else {
                return true;
            }
        }
        
        return false;
        
    }
};