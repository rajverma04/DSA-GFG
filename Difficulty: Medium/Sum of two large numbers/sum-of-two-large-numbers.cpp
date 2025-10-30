// User function template for C++
class Solution {
  public:
    string findSum(string &s1, string &s2) {
        // Your code goes here
        int carry = 0;
        int i = s1.size() - 1, j = s2.size() - 1;
        string str = "";
        
        while(i >= 0 && j >= 0) {
            int num1 = s1.back() - '0';
            int num2 = s2.back() - '0';
            s1.pop_back(), s2.pop_back();
            int sum = num1 + num2 + carry;
        
            char digit = '0' + (sum % 10);
            str.push_back(digit);
            carry = sum / 10;

            i--, j--;
        }
        
        while(i >= 0) {
            int sum = (s1.back() - '0') + carry;
            s1.pop_back();
            char digit = '0' + (sum % 10);
            str.push_back(digit);
            carry = sum / 10;
            i--;
        }
        
         while(j >= 0) {
            int sum = (s2.back() - '0') + carry;
            s2.pop_back();
            char digit = '0' + (sum % 10);
            str.push_back(digit);
            carry = sum / 10;
            j--;
        }
        
        if(carry > 0) {     //  if carry is left
            str.push_back(carry + '0');
        }
        
        
        reverse(str.begin(), str.end());
        
        while(str.size() > 1 && str[0] == '0') {  // <-- added leading-zero handling
            str.erase(str.begin());               // <-- added
        }
        return str;
    }
};