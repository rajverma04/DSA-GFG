class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto nbr : adj[node]) {
                inDeg[nbr]--;
                if (inDeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
       
        return count == numCourses;
        
    }
};