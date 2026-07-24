class Solution {
  public:
    vector<int> dp;
    int solve(int step, int n) {
        if(step > n) {
            return 0;
        }
        if(step == n) {
            return 1;
        }
        if(dp[step] != -1) {
            return dp[step];
        }
        
        return dp[step] = solve(step + 1, n) + solve(step + 2, n);
    }
    int countWays(int n) {
        dp.assign(n + 1, -1);    
        
        return solve(0, n);
    }
};
