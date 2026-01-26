class Solution {
  public:
    int countWays(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(grid[i][j] == 1) {       // not allowed to enter in this cell
            return 0;           
        }
        if(i == 0 && j == 0) {      // destination reached
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
    
        int up = countWays(grid, i - 1, j, dp);
        int left = countWays(grid, i, j - 1, dp);
    
        return dp[i][j] = up + left;
        
    }
    
    int uniquePaths(vector<vector<int>> &grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<int>> dp(i, vector<int> (j, -1));
        return countWays(grid, i - 1, j - 1, dp);       // row, col
    }
};