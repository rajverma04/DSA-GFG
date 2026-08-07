class Solution {
  public:
    vector<vector<int>> dp;
	int solve(int i, vector<int> &arr, int k) {
		if (i == 0) {
			if (k == 0 && arr[0] == 0)
				return 2;
			
			if (k == 0 || arr[0] == k)
				return 1;
			
			return 0;
		}
		if(dp[i][k] != -1) {
		    return dp[i][k];
		}
		int notTake = solve(i - 1, arr, k);
		int take = 0;
		if (arr[i] <= k) {
			take = solve(i - 1, arr, k - arr[i]);
		}
		return dp[i][k] = take + notTake;
	}
	
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum - diff < 0 || (totalSum -diff) % 2){
            return 0;
        }
        int s2 = (totalSum - diff) / 2;
        int target = s2;
        dp.assign(n, vector<int> (target + 1, -1));
        return solve(n - 1, arr, target);
    }
};


// s1 - s2 = D

// s1 = totalSum - s2
// totalSum - s1 - s2 = D
// (totalSum - D) / 2 = s2