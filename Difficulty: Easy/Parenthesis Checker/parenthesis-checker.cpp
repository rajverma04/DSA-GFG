class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        
        for(auto ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {       // if open braces come the push to stack
                st.push(ch);
            } else {
                if(st.empty()) {        // stack empty means no braces present
                    return false;
                }
                
                char top = st.top();        // get top element
                st.pop();       // delete the top element
                
                if((ch == ')' && top != '(') ||     // if closing braces of top element is not same type which is top return false
                    (ch == '}' && top != '{') || 
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        return st.empty();  // if all elements matched its pair means stack is empty
        
    }
};