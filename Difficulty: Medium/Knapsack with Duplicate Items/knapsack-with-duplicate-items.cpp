class Solution {
  public:
    vector<vector<int>> dp;
    int find(int index, vector<int> &val, vector<int> &wt, int capacity) {
        if(index == 0) {
            return ((int)(capacity / wt[0])) * val[0];
        }
        if(dp[index][capacity] != -1) {
            return dp[index][capacity];
        }
        
        int notTake = 0 + find(index - 1, val, wt, capacity);
        int take = INT_MIN;
        if(wt[index] <= capacity) {
            take = val[index] + find(index, val, wt, capacity - wt[index]);
        }
        return dp[index][capacity] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        dp.assign(n, vector<int> (capacity + 1, -1));
        
        return find(n - 1, val, wt, capacity);
    }
};