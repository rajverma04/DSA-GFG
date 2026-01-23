class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto x : arr) {
            freq[x]++;
        }
        
        // {freq, element}
        priority_queue<pair<int, int>> pq;
        
        for(auto it : freq) {
            pq.push({it.second, -it.first});
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            // auto [count, -ele] = pq.top();
            int count = pq.top().first;
            int ele = -pq.top().second;
            pq.pop();
            while(count--) {
                ans.push_back(ele);
            }
        }
        
        return ans;
    }
};