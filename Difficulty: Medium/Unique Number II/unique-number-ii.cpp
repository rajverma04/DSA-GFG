class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto x : arr) {
            mp[x]++;
        }
        vector<int> ans;
        for(auto it : mp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            } 
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};