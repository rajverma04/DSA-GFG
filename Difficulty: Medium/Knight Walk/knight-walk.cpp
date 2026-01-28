class Solution {
    
  public:
    bool checkValidMove(int i, int j, int N) {
        return (i > -1 && j > -1 && i < N && j < N);
    }

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        
        vector<vector<bool>> vis(N, vector<bool> (N, false));
        // converting to 0 based index
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;
        
        int row[8] = {-2,-2,2,2,-1,-1,1,1};
        int col[8] = {-1,1,-1,1,-2,2,-2,2};
        
        
        vis[KnightPos[0]][KnightPos[1]] = true;
        int steps = 0;
        
        queue<pair<int, int>> q;
        q.push({KnightPos[0], KnightPos[1]});
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [i, j] = q.front();
                q.pop();
                
                if(i == TargetPos[0] && j == TargetPos[1]) {
                    return steps;
                }
                
                for(int k = 0; k < 8; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];
        
                    if(checkValidMove(ni, nj, N) && !vis[ni][nj]) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
            
                }
            }
            steps++;
        }
        
        return -1;
    }
};