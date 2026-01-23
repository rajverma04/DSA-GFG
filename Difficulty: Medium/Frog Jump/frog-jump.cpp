class Solution {
  public:
    int cost(int n, vector<int>& height, vector<int> &dp) {
        if(n == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int left = cost(n - 1, height, dp) + abs(height[n] - height[n - 1]);
        int right = INT_MAX;
        if(n > 1) {
            right = cost(n - 2, height, dp) + abs(height[n] - height[n - 2]);
        }
        
        return dp[n] = min(left, right);
    }
    
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        
        return cost(n - 1, height, dp);
        
    }
};