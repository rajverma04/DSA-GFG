class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int zerocount = 0, onecount = 0, twocount = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) {
                zerocount++;
            } else if(arr[i] == 1) {
                onecount++;
            } else {
                twocount++;
            }
        }
        
        for(int i = 0; i < zerocount; i++) {
            arr[i] = 0;
        }
        for(int i = zerocount; i < zerocount + onecount; i++) {
            arr[i] = 1;
        }
        for(int i = zerocount + onecount; i < arr.size(); i++) {
            arr[i] = 2;
        }
        
    }
};