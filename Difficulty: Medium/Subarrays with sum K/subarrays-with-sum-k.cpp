class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        for(int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i] + arr[i - 1];
        } 
        
        int totalCount = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        for(auto x : arr) {
            if(mp[x - k] > 0) {
                totalCount += mp[x - k];
            }
            
            mp[x]++;
        }
        
        return totalCount;
    }
};