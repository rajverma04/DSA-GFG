class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> inDeg(numCourses);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                inDeg[it]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nbr : adj[node]) {
                inDeg[nbr]--;
                if (inDeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if(ans.size() != numCourses) {
            return {};
        }
        return ans;
        
    }
};