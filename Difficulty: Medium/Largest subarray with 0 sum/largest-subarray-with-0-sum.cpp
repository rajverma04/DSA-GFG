class Solution {
  public:
    int maxLength(vector<int>& arr) {
            
        unordered_map<int, int> mp;     // number, index
        
        int length = 0, sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == 0) {
                length = i + 1;
            } else if(mp.count(sum)) {
                length = max(length, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        
        
        return length;
        
    }
};