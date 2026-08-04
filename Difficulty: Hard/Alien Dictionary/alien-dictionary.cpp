class Solution {
  public:
    bool dfs(int i, vector<vector<int>> &adj, stack<int> &st, vector<int> &vis, vector<int> &pathVis) {
        vis[i] = 1;
        pathVis[i] = 1;
        
        for(int nbr : adj[i]) {
            if(!vis[nbr]) {
                if(dfs(nbr, adj, st, vis, pathVis)) {
                    return true;
                }
            } else if(pathVis[nbr]) {
                return true;
            }
        }
        pathVis[i] = 0;
        st.push(i);
        
        return false;
    }
    
    string findOrder(vector<string> &words) {
        // convert into directed graph
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> present(26, 0);
        // mark the character present
        for(auto &word : words) {
            for(auto ch : word) {
                present[ch - 'a'] = 1;
            }
        }
        
        // convert into directed graph
        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            
            for(int k = 0; k < len; k++) {
                if(s1[k] != s2[k]) {
                    adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                    found = true;
                    break;
                }
            }
            
            if(!found && s1.size() > s2.size()) {
                return "";
            }
        }
        
        vector<int> vis(26, 0);
        stack<int> st;
        vector<int> pathVis(26, 0);
        
        for(int i = 0; i < 26; i++) {
            if(present[i] && !vis[i]) {
                if(dfs(i, adj, st, vis, pathVis)) {
                    return "";
                }
            }
        }
        
        string str = "";
        while(!st.empty()) {
            str += char(st.top() + 'a');
            st.pop();
        }
        
        return str;
    }
};