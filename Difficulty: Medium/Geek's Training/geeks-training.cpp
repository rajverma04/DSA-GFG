class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int idx, int c, vector<vector<int>>& mat) {
        if(idx == 0) {
            int maxi = 0;
            for(int i = 0; i < 3; i++) {
                if(i != c) {
                    maxi = max(maxi, mat[idx][i]);
                }
            }
            
            return maxi;
        }
        
        if(dp[idx][c] != -1) {
            return dp[idx][c];
        }
        
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != c) {
                maxi = max(maxi, mat[idx][i] + solve(idx - 1, i, mat));
            }
        }
        
        return dp[idx][c] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        dp.assign(n + 1, vector<int> (4, 0));
        
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max({mat[0][0], mat[0][1], mat[0][2]});
        
        for(int i = 1; i < n; i++) {
            for(int last = 0; last < 4; last++) {
                dp[i][last] = 0;
                for(int j = 0; j < 3; j++) {
                    if(j != last) {
                        dp[i][last] = max(dp[i][last], dp[i - 1][j] + mat[i][j]);
                    }
                }
            }
        }
        
        return dp[n - 1][3];
        
        // return solve(n - 1, 3, mat);
    }
};