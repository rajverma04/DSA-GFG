class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        // if(arr.size() == 1) {
        //     return 0;
        // }
        // for(int i = 1; i < arr.size() - 1; i++) {
        //     if(i == arr.size()) {
        //         break;
        //     }
        //     if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
        //         return i;
        //     } 
        // }
        // return 0;
        
        
         int n = arr.size();
        
        // Handle edge cases
        if (n == 1) return 0;
        
        // Check first element
        if (arr[0] >= arr[1]) return 0;
        
        // Check middle elements - FIXED: i < n-1 to avoid index out of bounds
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
                return i;
            }
        }
        
        // Check last element
        if (arr[n - 1] >= arr[n - 2]) return n - 1;
        
        return 0;
    
    }
};