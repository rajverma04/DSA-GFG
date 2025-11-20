// User function Template for C++
class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string> st;
        
        if(arr.size() == 1) {
            return 1;
        }
        
        st.push(arr[0]);
        int i = 1, n = arr.size();
       
       while(i < n && !st.empty()) {
           if(st.top() == arr[i]) {
               st.pop();
               i++;
           }
           st.push(arr[i++]);
       }
       
       return st.size();
    }
};

