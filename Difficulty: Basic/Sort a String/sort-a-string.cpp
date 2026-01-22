string sort(string s) {
    vector<int> ans(26, 0);
    
    for(int ch : s) {
        ans[ch - 'a']++;
    }
    int k = 0;
    for(int i = 0; i < 26; i++) {
        while(ans[i] > 0) {
            s[k] = char('a' + i);
            k++;
            ans[i]--;
        }
    }
    
    return s;
}