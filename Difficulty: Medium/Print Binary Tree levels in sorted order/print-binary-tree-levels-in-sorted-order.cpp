
class Solution {
  public:
    vector<vector<int>> binTreeSortedLevels(int arr[], int n) {
        
        vector<vector<int>> ans;
        vector<int> res;
        
        int k = 1;
        int i = 0;
        
        while(i < n) {
            int levelSize = min(k, n - i);          // how many nodes actually on this level
            vector<int> res;
            res.reserve(levelSize);
            for (int j = 0; j < levelSize; ++j) {
                res.push_back(arr[i + j]);
            }
            
            sort(res.begin(), res.end());
            ans.push_back(res);
            
            i += levelSize;
            k *= 2;
        }
        return ans;
    }
};