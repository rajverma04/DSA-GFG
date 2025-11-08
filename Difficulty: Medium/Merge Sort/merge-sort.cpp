class Solution {
  public:
    void mergeArray(vector<int> &arr, int low, int mid, int high) {
        // temp array
        int *ans = new int[high - low + 1];
        int first = low, second = mid + 1, pos = 0;
        
        while(first <= mid && second <= high) {
            if(arr[first] < arr[second]) {
                ans[pos++] = arr[first++];
            } else {
                ans[pos++] = arr[second++];
            }
        }
        
        while(first <= mid) {
            ans[pos++] = arr[first++];
        }
        while(second <= high) {
            ans[pos++] = arr[second++];
        }
        
        // Copy back from temp array to original array
        for(int i = 0; i < pos; i++) {
            arr[low + i] = ans[i];
        }
        delete []ans;
    }
  
  
    void mergeSort(vector<int>& arr, int low, int high) {
        // code here
        if(low == high) {
            return;
        }
        
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeArray(arr, low, mid, high);
    }
};