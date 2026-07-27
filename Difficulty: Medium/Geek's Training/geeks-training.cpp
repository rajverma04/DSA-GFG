class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int idx, int n, int c, vector<vector<int>>& mat) {
        if(idx == 0) {
            int maxi = 0;
            for(int i = 0; i < 3; i++) {
                if(i != c) {
                    maxi = max(maxi, mat[idx][i]);
                }
            }
            
            return maxi;
        }
        if(idx < 0) {
            return 0;
        }
        if(dp[idx][c] != -1) {
            return dp[idx][c];
        }
        
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != c) {
                maxi = max(maxi, mat[idx][i] + solve(idx - 1, n, i, mat));
            }
        }
        
        return dp[idx][c] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        dp.assign(n + 1, vector<int> (4, -1));
        int c = -1;          // choice
        return solve(n - 1, n, 3, mat);
    }
};