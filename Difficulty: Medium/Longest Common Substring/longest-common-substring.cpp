class Solution {
  public:
    int find(int n, int m, string &s1, string &s2, int &ans, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        
        int len = 0;
        if(s1[n - 1] == s2[m - 1]) {
            len = 1 + find(n - 1, m - 1, s1, s2, ans, dp);
            ans = max(ans, len);
        }
        find(n - 1, m, s1, s2, ans, dp);
        find(n, m - 1, s1, s2, ans, dp);
        
        return dp[n][m] = len;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        int ans = 0;
        find(n, m, s1, s2, ans, dp);
        
        return ans;
        
    }
};