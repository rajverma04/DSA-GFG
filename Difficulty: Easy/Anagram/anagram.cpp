class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        // int count1[26] = {0};
        // int count2[26] = {0};
        // int index1 = 0, index2 = 0;
        // for(int i = 0; i < s1.size(); i++) {        // counting freq of s1
        //     index1 = s1[i] - 'a';
        //     count1[index1]++;
        // }
        // for(int i = 0; i < s2.size(); i++) {        // counting freq of s2
        //     index2 = s2[i] - 'a';
        //     count2[index2]++;
        // }
        
        // for(int i = 0; i < 26; i++) {       
        //     if(count1[i] != count2[i]) {    // if freq in both diff. then not anagram
        //         return false;
        //     }
        // }
        
        
        // M2: frequency
        unordered_map<char, int> mp;
        
        for(auto ch : s1) {     // Count freq of characters in s1
            mp[ch]++;
        }
        
        for(auto ch : s2) {     // Decrease freq using s2
            mp[ch]--;
            if(mp[ch] < 0) {
                return false;
            }
        }
        
        return true;
    }
};