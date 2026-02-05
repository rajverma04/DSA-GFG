class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int res = 0;
        for(auto x : arr) {
            res ^= x;
        }
        
        return res;
    }
};