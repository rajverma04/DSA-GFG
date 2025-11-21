class Solution {
  public:
    string removeKdig(string &s, int k) {
        stack<int> st;
        string ans;
        char ch;
        
        for(auto x : s) {
            int digit = x - '0';
            while(st.size() && st.top() > digit && k) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        while(k--) {
            st.pop();
        }
        
        while(st.size()) {
            ch = '0' + st.top();
            st.pop();
            
            ans.push_back(ch);
        }
        
        // remove zero
        int i = ans.size() - 1;
        while(i >= 0 && ans[i] == '0') {
            ans.pop_back();
            i--;
        }
        
        if(ans.size() == 0) {
            return "0";
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};