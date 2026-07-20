class Solution {
	public:
	
	vector<int> leastPrimeFactor(int n) {
		
		static vector<int> lpf = []() {
			static const int N = 100001;
			vector<int> spf(N);
			iota(spf.begin(), spf.end(), 0);
			
			for (int i = 2; i * i < N; i++) {
				if (spf[i] == i) {
					for (int j = i * i; j < N; j += i) {
						if (spf[j] == j) {
							spf[j] = i;
						}
					}
				}
			}
			return spf;
		}();
		
		vector<int> ans;
		
		ans.push_back(0);
		for (int i = 1; i <= n; i++) {
			ans.push_back(lpf[i]);
		}
		
		return ans;
		
	}
};
