class Solution {
  public:
    vector<int> dp;
    
    int solve(int i, int n, vector<int>& arr) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        
        return dp[i] = max(solve(i + 1, n, arr), arr[i] + solve(i + 2, n, arr));
    }
    
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n + 1, 0);
        
        // return solve(0, n, arr);
        
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        for(int i = 2; i < n; i++) {
            int pick = arr[i] + dp[i - 2];
            int notPick = dp[i - 1];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[n - 1];
        
    }
};