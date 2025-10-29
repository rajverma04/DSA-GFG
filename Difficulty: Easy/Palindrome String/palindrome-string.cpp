class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        string str = s;
        reverse(str.begin(), str.end());
        return (str == s);
    }
};