class Solution {
  public:
    int minFlips(string& s) {
        // code here
        int count1 = 0, count2 = 0;
        
        for(int i = 0; i < s.size(); i++) {
             // Expected char for pattern starting with 0
            if(s[i] != (i % 2 == 0 ? '0' : '1')) {
                count1++;
            }
            
            // Expected char for pattern starting with 1
            if(s[i] != (i % 2 == 0 ? '1' : '0')) {
                count2++;
            }
        }
        
        
        return min(count1, count2);
    }
};
