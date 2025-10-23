class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int first = 0, last = arr.size() - 1 ;
        sort(arr.begin(), arr.end());
        while(first < last) {
            if(arr[first] + arr[last] == target) {
                return true;
                break;
            } else if(arr[first] + arr[last] < target) {
                first++;
            } else {
                last--;
            }
        }
        
        return false;
    }
};