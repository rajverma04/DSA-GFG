// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string s1, string s2) {
    // Your code goes here
    int str1[26] = {0};
    int str2[26] = {0}; 
    int count = 0;
    for(int i = 0; i < s1.size(); i++) {
        int index1 = s1[i] - 'a';
        str1[index1]++;
    }
    for(int i = 0; i < s2.size(); i++) {
        int index2 = s2[i] - 'a';
        str2[index2]++;
    }
    
    for(int i = 0; i < 26; i++) {
        if(str1[i] == str2[i]) {
            continue;
        } else if(str1[i] > str2[i]) {
            count += str1[i] - str2[i];
        } else {
            count += str2[i] - str1[i];
        }
    }
    return count;
    
}