class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();     // lenght of arr
        int start = arr[0], end = 0, mid;
        
        if(k > n) {     // if noOfStud. > noOfBooks
            return -1;
        }
        
        for(int i = 0; i < n; i++) {
            end += arr[i];
            
            if(start < arr[i]) {    // storing max value in start
                start = arr[i];
            }
        }
        
        int ans;
        while(start <= end) {
            mid = (start + end) / 2;
            int sum = 0, count = 1;     // sum: how many pages allocated, count: how many stud. allocated books
            
            for(int i = 0; i < n; i++) {
                sum += arr[i];
                if(sum > mid) {
                    count++;
                    sum = arr[i];   // first book allocated in that array
                }
            }
            
            if(count <= k) {    //  if books can easily distributed, so move left
                end = mid - 1;
                ans = mid;
            } else {    // if books cannot easily distributed, so move right
                start = mid + 1;
            }
        }
        
        return ans;
    }
};