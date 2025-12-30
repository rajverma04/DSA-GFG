// User function Template for C++

class Solution {
  public:
    int minimumStep(int n) {
        
        int count_edge = 0;
        
        while(n >= 3) {
            count_edge += n % 3;
            n /= 3;
            count_edge++;
        }
        
        count_edge += n;
        count_edge--;
        return count_edge;
    }
};