class Solution {
  public:
    int minCost(vector<int>& arr) {
        if(arr.size() == 1) {
            return 0;
        }
        
        priority_queue<int, vector<int>, greater<int> > q;
        
        while(arr.size() != 0) {
            q.push(arr.back());
            arr.pop_back();
        }
        
        int cost = 0;
        while(q.size() != 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            
            q.push(a+b);
            
            cost += a + b;
        }
        
        return cost;
    }
};