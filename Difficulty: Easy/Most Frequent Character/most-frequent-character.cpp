class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int count[26] = {0};
        
        for(int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            count[index]++;
        }
        int max = -1;
        int index = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i] > max) {        
                max = count[i];
                index = i;
            } else if(count[i] == max) {        // if some count is equal then print the smaller lexicographically
                if(i < index) {
                    index = i;
                }
            }
        }
        
        return ('a' + index);
    }
};