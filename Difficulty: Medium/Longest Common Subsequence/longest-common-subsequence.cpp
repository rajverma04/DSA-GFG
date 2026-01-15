class Solution {
  public:
    int find(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(s1[i - 1] == s2[j - 1]) {        // both string matched
            return dp[i][j] = 1 + find(i - 1, j - 1, s1, s2, dp);
        } else {                // not matched
            return dp[i][j] = max(find(i - 1, j, s1, s2, dp), find(i, j - 1, s1, s2, dp));     
        }
        
    }
    int lcs(string &s1, string &s2) {
        int i = s1.size();
        int j = s2.size();
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        
        return find(i, j, s1, s2, dp);
    }
};
