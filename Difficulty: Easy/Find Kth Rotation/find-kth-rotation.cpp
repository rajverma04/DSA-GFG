class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start = 0, mid, end = arr.size() - 1;
        
        
        while(start < end) {
            mid = (start + end) / 2;    
            if(arr[mid] > arr[end]) {       // Rotation is in right half
                
                start = mid + 1;
            } else {        // Rotation is in left half (including mid)
                end = mid;
            }
        }
        
        return start;
    }
};
