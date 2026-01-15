class Solution {
  public:
    int find(int n, int m, string &s, string &str, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        
        if(s[n - 1] == str[m - 1]) {
            return dp[n][m] = 1 + find(n - 1, m - 1, s, str, dp);
        } else {
            return dp[n][m] = max(find(n - 1, m, s, str, dp), find(n, m - 1, s, str, dp));
        }
    }
    int longestPalinSubseq(string &s) {
        string str = s;
        reverse(str.begin(), str.end());
        int n = s.size();
        int m = str.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return find(n, m, s, str, dp);
    }
};