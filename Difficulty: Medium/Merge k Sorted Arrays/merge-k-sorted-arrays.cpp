class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> ans;
        
        priority_queue<int, vector<int>, greater<int> > q;
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                q.push(mat[i][j]);
            }
        }
        
        
        while(!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        
        return ans;
    }
};