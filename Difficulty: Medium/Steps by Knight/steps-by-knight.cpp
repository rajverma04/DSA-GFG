class Solution {
  public:
    bool check(int i, int j, int n) {
        return i > 0 && i <= n && j > 0 && j <= n;
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int row[8] = {2,2,-2,-2,1,1,-1,-1};
        int col[8] = {1,-1,1,-1,2,-2,2,-2};
    
        queue<pair<pair<int, int>, int>> q;         // row, col, step
        q.push({{knightPos[0], knightPos[1]}, 0});      
        
        vector<vector<bool>>visited(n + 1, vector<bool>(n + 1, 0));
        visited[knightPos[0]][knightPos[1]] = true;
        
        int i, j, step = 0;
        
        while(!q.empty()) {
            i = q.front().first.first;
            j = q.front().first.second;
            step = q.front().second;
            q.pop();
            
            if(i == targetPos[0] && j == targetPos[1]) {
                return step;
            }
            
            for(int k = 0; k < 8; k++) {
                if(check(i + row[k], j + col[k], n) && !visited[i + row[k]][j + col[k]]) {
                    visited[i + row[k]][j + col[k]] = true;
                    q.push({{i + row[k], j + col[k]}, step + 1});
                    
                }
            }
        }
        
        
        return -1;
    }
};