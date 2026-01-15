class Solution {

  public:
    int findLCS(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        
        if(s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + findLCS(n - 1, m - 1, s1, s2, dp);
        } else {
            return dp[n][m] = max(findLCS(n - 1, m, s1, s2, dp), findLCS(n, m - 1, s1, s2, dp));
        }
    }
    int minOperations(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        int lcs = findLCS(n, m, s1, s2, dp);
        return (n + m)  - (2 * lcs);
    }
};