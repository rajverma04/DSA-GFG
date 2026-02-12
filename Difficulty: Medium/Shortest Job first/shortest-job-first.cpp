// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        
        long long time = 0;
        long long waitingTime = 0;
        for(auto x : bt) {
            waitingTime += time;
            time += x;
        }
        
        return waitingTime / bt.size();
        
    }
};