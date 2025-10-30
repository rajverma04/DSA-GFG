class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        int count[26] = {0};
        int first = 0, second = 1, maxSubstring = 1;
        
        count[s[0] - 'a']++;        // Mark first character as present
        while(second < s.size()) {  
            // checks if the character at position second is already present in the current sliding window.
            while(count[s[second] - 'a']) {
                count[s[first] - 'a'] = 0;       // Remove character from window
                first++;        // Move left pointer right
            }
            count[s[second] - 'a'] = 1;     // Mark character as present
            maxSubstring = max(maxSubstring, (second - first + 1));
            
            
            second++;
        }
        return maxSubstring;
        
    }
};