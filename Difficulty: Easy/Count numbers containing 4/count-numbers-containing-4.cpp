
class Solution {
  public:
    int find(int n, int &count) {
        
        for(int i = 1; i <= n; i++) {
            int num = i;
            while(num != 0) {
                int digit = num % 10;
                if(digit == 4) {
                    count++;
                    break;
                }
                num /= 10;
            }
        }
        
        return count;
    }
    
    int countNumberswith4(int n) {
        int count = 0;
        return find(n, count);
    }
};
