class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        
        // for(int i = 0; i <= arr.size() - k; i++) {           // brute force
        //     unordered_set<int> nums;
        //     for(int j = i; j < i + k; j++) {
        //         nums.insert(arr[j]);
        //     }
        //     ans.push_back(nums.size());
        // }
        
        
        
        // M2: optimized
        unordered_map<int, int> freq;

        int n = arr.size();

        // first window
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());

        // remaining windows
        for (int i = k; i < n; i++) {
            // remove outgoing element
            freq[arr[i - k]]--;
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }

            // add incoming element
            freq[arr[i]]++;

            ans.push_back(freq.size());
        }
        
        return ans;
    }
};