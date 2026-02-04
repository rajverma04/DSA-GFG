class Solution {
  public:
    vector<int> dp;
    int solve(int index, vector<int> &arr) {
        if(index == 0) {
            return arr[0];
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        
        return dp[index] = max(arr[index], arr[index] + solve(index - 1, arr));
    }
    int maxSubarraySum(vector<int> &arr) {
        
        int ans = arr[0];
        dp.assign(arr.size(), -1);
        for(int i = 1; i < arr.size(); i++) {
            ans = max(ans, solve(i, arr));
        }
        
        return ans;
    }
};