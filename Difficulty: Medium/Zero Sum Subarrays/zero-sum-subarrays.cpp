class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        if(arr.size() == 1) {
            return 1;
        }
        
        for(int i = 1; i < arr.size(); i++) {       // prefix sum
            arr[i] = arr[i] + arr[i - 1];
        }
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        int totalCount = 0;
        for(auto x : arr) {
            if(mp[x] > 0) {
                totalCount += mp[x];
            }
            mp[x]++;
        }
        
        return totalCount;
        
    }
};