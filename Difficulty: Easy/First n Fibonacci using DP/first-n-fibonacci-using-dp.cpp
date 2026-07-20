class Solution {
  public:
    vector<int> fibonacciNumbers(int n) {
        const int MOD = 1e9 + 7;
        if(n == 0) {
            return {0};
        }
        if(n == 1) {
            return {0, 1};
        }
        int a = 0, b = 1;
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        for(int i = 2; i <= n; i++) {
            int res = (a + b) % MOD;
            a = b % MOD;
            b = res % MOD;
            ans.push_back(res);
        }
        
        return ans;
    }
};