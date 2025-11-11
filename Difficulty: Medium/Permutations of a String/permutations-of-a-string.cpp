class Solution {
  public:
    vector<string> findPermutation(string &s) {
        vector<string> ans;
        
        if(s.empty()) {
            return ans;
        }
        
        backtrack(s, 0, ans);
        
        // Remove duplicates if any and sort
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
        
    }
    
    void backtrack(string &s, int start, vector<string> &ans) {
        if(start == s.size()) {
            ans.push_back(s);
            return;
        }
        
        // Set to track used characters at current position
        unordered_set<char> used;
        
        for(int i = start; i < s.size(); i++) {
            // Skip if character already used at this position (avoid duplicates)
            if(used.find(s[i]) != used.end()) {
                continue;
            }
            
            used.insert(s[i]);
            
            swap(s[start], s[i]);
            backtrack(s, start + 1, ans);
            swap(s[start], s[i]);
        }
    }
    
};
