class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(int idx, vector<int>& arr, int target) {
        if(target == 0) {
            return true;
        }
        if(idx == 0) {
            return arr[0] == target;
        }
        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        bool notTake = solve(idx - 1, arr, target);
        bool take = false;
        if(arr[idx] <= target) {
            take = solve(idx - 1, arr, target - arr[idx]);
        }
        
        return dp[idx][target] = take || notTake;
    }
    
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        if(totalSum % 2) {
            return false;
        }
        int n = arr.size();
        int target = totalSum / 2;
        dp.assign(n, vector<int> (target + 1, -1));
        return solve(n - 1, arr, target);
    }
};