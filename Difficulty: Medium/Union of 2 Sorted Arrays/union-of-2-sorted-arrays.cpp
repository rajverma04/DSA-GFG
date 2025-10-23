class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        
        // remove duplicates
        
        int note = 0;
        int index = 0;
        for(int i = 0; i < a.size(); i++) {
            if(note != a[i]) {
                a[index++] = a[i];
                note = a[i];
            }
        }
        a.resize(index);
        note = 0, index = 0;
        for(int i = 0; i < b.size(); i++) {
            if(note != b[i]) {
                b[index++] = b[i];
                note = b[i];
            }
        }
        b.resize(index);
         
        vector<int> ans;
        
        int i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                ans.push_back(a[i]);
                k++, i++, j++;
            } else if(a[i] > b[j]) {
                ans.push_back(b[j]);
                j++;
            } else {
                ans.push_back(a[i]);
                i++;
            }
        }
        
        while(i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }
        while(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};