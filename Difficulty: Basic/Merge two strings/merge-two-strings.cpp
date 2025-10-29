
string merge(string S1, string S2) {
    // your code here
    if(S1.size() == 0 && S2.size() == 0) {
        return "";
    }
    string str = "";
    
    
    int i = 0, j = 0;
    while(i < S1.size() && j < S2.size()) {
        str.push_back(S1[i++]);
        str.push_back(S2[j++]);
    }
    while(i < S1.size()) {
        str.push_back(S1[i++]);
    }
    while(j < S2.size()) {
        str.push_back(S2[j++]);
    }
    return str;
    
}