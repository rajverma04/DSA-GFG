class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, 0);     // initialize all with 0 of size n
        
        for(int i = 0; i < n; i++) {
            int num = arr[i];
            
            if(num >= 1 && num <= n) {
                ans[num - 1]++;     // storing at zero based index
            }
        }
        return ans;
    }
};
