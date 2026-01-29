class Solution {
  public:
    bool fun(int index, vector<int> &arr, int sum, vector<vector<int>> &dp) {
        if(sum == 0) {
            return true;
        }
        
        if(index == 0) {
            return (arr[0] == sum);
        }
        if(dp[index][sum] != -1) {
            return dp[index][sum];
        }
        
        bool notTake = fun(index - 1, arr, sum, dp);
        bool take = false;
        if(arr[index] <= sum) {
            take = fun(index - 1, arr, sum - arr[index], dp);
        }
        
        return dp[index][sum] = take || notTake;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return fun(n - 1, arr, sum, dp);
    }
};