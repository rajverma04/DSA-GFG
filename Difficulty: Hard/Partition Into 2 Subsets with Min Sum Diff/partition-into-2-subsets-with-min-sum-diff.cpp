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
    
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        int target = totalSum / 2;
        dp.assign(n, vector<int> (target + 1, -1));
        
        int ans = INT_MAX;
        
        for(int s1 = 0; s1 <= target; s1++) {
            if(solve(n - 1, arr, s1)) {
                int s2 = totalSum - s1;
                ans = min(ans, abs(s1 - s2));
            }
        }
        
        return ans;
    }
};
