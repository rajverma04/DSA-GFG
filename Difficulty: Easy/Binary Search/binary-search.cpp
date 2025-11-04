class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        int start = 0, end = n - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == k) {
                ans = mid;        // record this occurrence
                end = mid - 1;    // keep searching left for earlier occurrence
            } else if (arr[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans; // -1 if not found
    }
};
