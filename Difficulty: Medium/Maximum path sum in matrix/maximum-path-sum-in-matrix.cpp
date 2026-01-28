// User function Template for C++

class Solution {
  public:
    int maxSum(int i, int j, vector<vector<int>>& mat, vector<vector<int>> &dp) {
        if(j < 0 || j >= mat[0].size()) {       // out of column boundary
            return -1e9;
        }
        
        if(i == 0) {            // reached to first row
            return mat[0][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int leftDiagonal = mat[i][j] + maxSum(i - 1, j - 1, mat, dp);
        int rightDiagonal = mat[i][j] + maxSum(i - 1, j + 1, mat, dp);
        int up = mat[i][j] + maxSum(i - 1, j, mat, dp);
        
        return dp[i][j] = max(leftDiagonal, max(rightDiagonal, up));
    }
    
    
    int maximumPath(vector<vector<int>>& mat) {
        
        int m = mat.size();     // total rows
        int n = mat[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int maxi = -1e8;
        for(int j = 0; j < n; j++) {        // column wise
            maxi = max(maxi, maxSum(m - 1, j, mat, dp));        // start from last row
        }
        
        return maxi;
    }
};