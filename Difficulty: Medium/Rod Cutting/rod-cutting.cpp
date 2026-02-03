// Unbounded Knapsack problem

class Solution {
  public:
    vector<vector<int>> dp;
    
    int find(int index, int n, vector<int> &price) {
        if(index == 0) {
            return n * price[0];
        }
        if(dp[index][n] != -1) {
            return dp[index][n];
        }
        int notTake = 0 + find(index - 1, n, price);
        
        int take = INT_MIN;
        int rodLength = index + 1;
    
        if(rodLength <= n) {
            take = price[index] + find(index, n - rodLength, price);
        }
        
        return dp[index][n] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        dp.assign(n, vector<int> (n + 1, -1));
        
        return find(n - 1, n, price);
    }
};