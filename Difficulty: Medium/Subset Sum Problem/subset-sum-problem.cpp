class Solution {
  public:
    vector<vector<int>> dp;
    
    bool solve(int i, vector<int>& arr, int sum) {
        if(sum == 0) {
            return true;
        }
        if(i == 0) {
            return arr[0] == sum;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        bool notTake = solve(i - 1, arr, sum);
        bool take = false;
        if(sum >= arr[i]) {
            take = solve(i - 1, arr, sum - arr[i]);
        }
        return dp[i][sum] = take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        dp.assign(n, vector<int> (sum + 1, -1));
        
        return solve(n - 1, arr, sum);
    }
};