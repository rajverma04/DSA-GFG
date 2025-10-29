class Solution {
  public:
    int binarySubstring(string& s) {
        // code here
        
        int countOnes = 0;
        for(char ch : s) {
            if(ch == '1') {
                countOnes++;
            }
        }
        // no. of combination = nc2 = n*(n-1)/2
        return countOnes * (countOnes - 1) / 2;
        
        
        
        // T -> O(n*n)
        // int count = 0;
        // for(int i = 0; i < s.size(); i++) {
        //     for(int j = i + 1; j < s.size(); j++) {
        //         if(s[i] == '1' && s[j] == '1') {
        //             count++;
        //         }
        //     }
        // }
        
        // return count;
    }
};