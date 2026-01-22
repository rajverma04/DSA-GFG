class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        while(!s.empty() && s.front() == '.') {     // remove front dot
            s.erase(s.begin());
        }
        
        while(!s.empty() && s.back() == '.') {      // remove back dot
            s.pop_back();
        }
        
    
        stack<char> st;
        int n = s.size() - 1;
        string str = "";
        for(int i = n; i >= 0; i--) {
            if(s[i] != '.') {
                st.push(s[i]);
            } else {
                while(!st.empty()) {
                    str += st.top();
                    st.pop();
                }
                if(str.back() != '.') {   // 🔥 FIX
                    str += '.';
                }
            }
        }
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        
        return str;
    }
};