class Solution {
  public:
    vector<int> sieve(int n) {
        vector<int> prime(n + 1, 1);
        
        for(int i = 2; i <= sqrt(n); i++) {
            if(prime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        vector<int> ans;
        for(int i = 2; i <= n; i++) {
            if(prime[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};