class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        vector<int> ans;
        
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        
        for(auto x : arr) {
            mp[x]++;
        }
        
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
