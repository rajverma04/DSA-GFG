// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        for(int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
        return s;
    }
};
