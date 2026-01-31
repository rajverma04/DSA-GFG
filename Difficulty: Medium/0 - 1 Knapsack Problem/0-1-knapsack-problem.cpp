class Solution {
  public:
    int find(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
        // Base Condition
        if(index == 0) {
            if(wt[0] <= W) {
                return val[0];
            }
            return 0;
        }
        if(dp[index][W] != -1) {
            return dp[index][W];
        }
        
        int notTake = 0 + find(index - 1, W, val, wt, dp);
        int take = INT_MIN;
        
        if(wt[index] <= W) {     // current weight < bag weight
            take = val[index] + find(index - 1, W - wt[index], val, wt, dp);
        }
        
        return dp[index][W] = max(take, notTake);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size(); // or wt.size() as both equal
        vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));
        return find(n - 1, W, val, wt, dp);
        
    }
};