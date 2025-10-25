class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        return arr[arr.size() - 1];
    }
};
