class Solution {
  public:
    
    int solve(int idx, vector<int> &height, vector<int> &dp) {
        int n = height.size();
        if(idx == n - 1) {
            return 0;
        }
        
        
        if(dp[idx] != -1) {
            return dp[idx];
        }
        
        int oneStep = abs(height[idx] - height[idx + 1]) + solve(idx + 1, height, dp);
        
        int twoStep = INT_MAX;
        
        if(idx + 2 < n) {
            twoStep = abs(height[idx] - height[idx + 2]) + solve(idx + 2, height, dp);
        }
        
        return dp[idx] = min(oneStep, twoStep);
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        
        return solve(0, height, dp);
    }
};