class Solution {
  public:
    vector<vector<int>> dp;
    int sol(int i, vector<int> &price, int N) {
        if(i < 0) {
            return 0;
        }
        int rodlen = i + 1;     // 1 based idx
        if(i == 0) {
            if(N % rodlen == 0) {       // rodlen = 1
                return (N / rodlen) * price[0];
            }
            return 0;
        }
        if(dp[i][N] != -1) {
            return dp[i][N];
        }
        int notTake = sol(i - 1, price, N);
        int take = INT_MIN;
        if(rodlen <= N) {
            take = price[i] + sol(i, price, N - rodlen);
        }
        return dp[i][N] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        dp.assign(n, vector<int> (n + 1, 0));
        // return sol(n - 1, price, n);
        int rodlen = 1;
        // for(int N = 0; N <= n; N++) {
        //     dp[0][N] = (N / rodlen) * price[0];
        // }
        vector<int> prev(n + 1, 0);
        for(int N = 0; N <= n; N++) {
            prev[N] = (N / rodlen) * price[0];
        }
        for(int i = 1; i < n; i++) {
            rodlen = i + 1;
            for(int N = 0; N <= n; N++) {
                int notTake = prev[N];
                int take = INT_MIN;
                if(rodlen <= N) {
                    take = price[i] + prev[N - rodlen];
                }
                prev[N] = max(take, notTake);
            }
        }
        
        return prev[n];
    }
};