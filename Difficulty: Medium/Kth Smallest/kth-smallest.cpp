class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto num : arr) {
            pq.push(num);
        }
        
        while(k != 1) {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};