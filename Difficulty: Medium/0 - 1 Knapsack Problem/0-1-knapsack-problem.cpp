class Solution {
  public:
    int find(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
        // Base Condition
        if(W == 0) {
            return 0;
        }
        
        if(index == 0) {
            return 0;
        }
        if(dp[index][W] != -1) {
            return dp[index][W];
        }
        
        
        if(wt[index - 1] > W) {     // current weight > bag weight
            return dp[index][W] = find(index - 1, W, val, wt, dp);
        } else {    // current weight < bag weight : have two option take it or do not take it
            return dp[index][W] = max(val[index - 1] + find(index - 1, W - wt[index - 1], val, wt, dp), find(index - 1, W, val, wt, dp));
        }
        
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size(); // or wt.size() as both equal
        vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));
        return find(n, W, val, wt, dp);
        
    }
};