class Solution {
	public:
	vector<int> parent, size;
	int find(int node) {
		if (parent[node] == node) {
			return node;
		}
		
		return parent[node] = find(parent[node]);
	}
	bool unionSet(int u, int v) {
		int pu = find(u), pv = find(v);
		
		if (pu == pv) {
			return false;
		}
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		} else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
		
		return true;
		
	}
	
	int spanningTree(int V, vector<vector<int>> & edges) {
		parent.resize(V);
		size.resize(V, 1);
		
		for (int i = 0; i < V; i++) {
			parent[i] = i;
		}
		sort(edges.begin(), edges.end(),
		[](const vector<int>& a, const vector<int>& b) {
			return a[2] < b[2];
		});
		
		int mstWeight = 0;
		
		for (auto e : edges) {
			int u = e[0], v = e[1];
			
			if (unionSet(u, v)) {
				mstWeight += e[2];
			}
		}
		
		return mstWeight;
	}
};
