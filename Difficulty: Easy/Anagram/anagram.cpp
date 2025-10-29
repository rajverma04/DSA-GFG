class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int count1[26] = {0};
        int count2[26] = {0};
        int index1 = 0, index2 = 0;
        for(int i = 0; i < s1.size(); i++) {
            index1 = s1[i] - 'a';
            count1[index1]++;
        }
        for(int i = 0; i < s2.size(); i++) {
            index2 = s2[i] - 'a';
            count2[index2]++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(count1[i] != count2[i]) {
                return false;
            }
        }
        
        return true;
    }
};