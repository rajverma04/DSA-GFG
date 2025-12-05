class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, rear = 0, front = 0;
        int n = gas.size();
        
        while(front < n) {
            totalGas += gas[rear] - cost[rear];
            if(totalGas < 0) {
                if(rear < front) {
                    return -1;
                }
                front = rear + 1;
                rear = front;
                totalGas = 0;
            } else {
                rear = (rear + 1) % n;
                if(front == rear) {
                    return front;
                }
            }
        }
         return -1;
        
    }
};