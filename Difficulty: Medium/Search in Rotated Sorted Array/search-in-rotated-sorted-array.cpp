class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        
        int start = 0, mid, end = arr.size() - 1;
        
        while(start <= end) {
            mid = end + (start - end) / 2;
            
            if(arr[mid] == key) {       // if mid element is the key
                return mid;
            } else if(arr[mid] > arr[start]) {  // left sorted from mid
                if(arr[mid] < key || key < arr[start]) {    // if key lie in left side
                    start = mid + 1;
                } else {        // if key lie in right side
                    end = mid - 1;
                }
            } else {    // right sorted
                if(arr[start] <= key || key < arr[mid]) {   
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        
        return -1;      // key not found
    }
};