class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        vector<int> ans(26, 0);
        
        for(int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';       
            ans[index]++;
        }
        
        int maxAns = -1;
        int index = 0;
        for(int i = 0; i < 26; i++) {
            if(ans[i] > maxAns) {
                maxAns = max(maxAns, ans[i]);
                index = i;
            }
            
        }
        char ch = 'a' + index;
        return ch;
        
    }
};