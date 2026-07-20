class Solution {
  public:
    vector<int> primeRange(int left, int right) {
        
        static vector<bool> prime = []() {
            const int N = 1000001;
            vector<bool> p(N, true);
            p[0] = false;
            p[1] = false;
            for(int i = 2; i * i < N; i++) {
    
                if(p[i]) {     // prime
                    for(int j = i * i; j < N; j += i) {
                        p[j] = false;       // mark every multiple of prime as not prime(as muliple of prime cannot be prime number)
                    }
                }
            }
            
            return p;
        }();

        vector<int> ans;

        for(int i = left; i <= right; i++) {
            if(prime[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};