class Solution {
  public:
    vector<vector<int>> dp;
    int longCommSubstr(string& t1, string& t2) {
        int n = t1.size();
        int m = t2.size();
        if (t1 == t2) {
            return t1.size();
        }
        dp.assign(n + 1, vector<int>(m + 1, 0));
       
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
        
    }
};