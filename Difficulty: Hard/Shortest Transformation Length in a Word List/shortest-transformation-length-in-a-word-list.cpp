class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        unordered_set<string> st(words.begin(), words.end());
        queue<pair<string, int>> q;
        q.push({s, 1});
        st.erase(s);
        
        while(!q.empty()) {
            auto [w, c] = q.front();
            q.pop();
            
            if(w == e) {
                return c;
            }
            for(int i = 0; i < w.size(); i++) {
                char org = w[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    w[i] = ch;
                    if(st.find(w) != st.end()) {
                        st.erase(w);
                        q.push({w, c + 1});
                    }
                }
                w[i] = org;
            }
        }
        return 0;
    }
};