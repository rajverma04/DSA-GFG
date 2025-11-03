class Solution {
  public:
    int minChar(string &s) {
        // code here
        string originalstr = s;
        reverse(s.begin(), s.end());
        s = originalstr + '$' + s;
        char str[s.size() + 1];
        
    
        int n = s.size();
        int LPS[n];
        LPS[0] = 0;
        
        int first = 0, second = 1;
        while(second < s.size()) {
            if(s[first] == s[second]) {
                first++;
                LPS[second] = first;
                second++;
            } else {
                if(first != 0) {
                    first = LPS[first - 1];
                } else {
                    LPS[second] = 0;
                    second++;
                }
            }
        }
        
        return originalstr.size() - LPS[n - 1];
        
        
        // M2
        // int n = s.length();
        // int left = 0, right = n - 1;
        // int added = 0;
        
        // while (left < right) {
        //     if (s[left] == s[right]) {
        //         left++;
        //         right--;
        //     } else {
        //         added++;
        //         left = 0;
        //         right = n - 1 - added;
        //     }
        // }
        
        // return added;
    }
};
