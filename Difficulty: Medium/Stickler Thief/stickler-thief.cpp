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
        dp.assign(n + 1, -1);
        
        return solve(0, n, arr);
        
    }
};