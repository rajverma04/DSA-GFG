class Solution {
  public:
    void sort012(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto it : arr) {
            pq.push(it);
        }
        
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = pq.top();
            pq.pop();
        }
        
    }
};