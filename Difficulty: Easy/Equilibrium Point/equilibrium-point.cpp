class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 0) {        // if array is empty
            return -1;
        }
        if(n == 1) {        // if single element is prensent in array(itself in equilibrium)
            return 0;
        }
        int leftsum = 0, rightsum = 0;
        
        for(int i = 0; i < n; i++) {
            rightsum += arr[i];
        }
        
        for(int i = 0; i < n; i++) {
            rightsum -= arr[i];
            if(leftsum == rightsum) {
                return i;
            } else {
                leftsum += arr[i];
            }
        }
        
        
        // if no such point exists
        return -1;
    }
};