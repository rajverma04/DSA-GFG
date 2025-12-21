class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        if(n <= 1) {
            return 1;
        }
        
        return floor(log2(n));
        
    }
};