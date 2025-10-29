// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        // for(int i = 0; i < s.size() / 2; i++) {
        //     swap(s[i], s[s.size() - 1 - i]);
        // }
        // return s;
        
        // two pointer method
        
        int start = 0, end = s.size() - 1;
        
        while(start < end) {
            swap(s[start], s[end]);
            start++, end--;
        }
        return s;
    }
};
