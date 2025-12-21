class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        
        priority_queue<int> q;
        
        for(auto x : arr) {
            q.push(x);
        }
        
        vector<int> ans;
        while(k > 0) {
            ans.push_back(q.top());
            q.pop();
            k--;
        }
        
        return ans;
        
    }
};