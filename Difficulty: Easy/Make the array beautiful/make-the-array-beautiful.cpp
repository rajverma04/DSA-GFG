// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++) {
            if(st.empty()) {
                st.push(arr[i]);
            } else if(arr[i] >= 0) {    // positive
                if(st.top() >= 0) {    // positive
                    st.push(arr[i]);
                } else {    // stack top < 0 && arr[i] > 0
                    st.pop();
                }
            } else {    // arr[i] < 0 (negative)
                if(st.top() < 0) {  // arr[i] < 0 && top < 0
                    st.push(arr[i]);
                } else {    // top > 0 && arr[i] < 0
                    st.pop();
                }
            }
        }

        
        vector<int> ans(st.size());
        int i = st.size() - 1;
        while(!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};