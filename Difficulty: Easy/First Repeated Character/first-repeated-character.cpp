class Solution {
  public:
    string firstRepChar(string s) {
        unordered_set<char> st;
        
        for(int i = 0; i < s.length(); i++) {
            if(st.find(s[i]) != st.end()) {
                return string(1, s[i]);
            }
            st.insert(s[i]);
        }
        
        return "-1";
    }
};