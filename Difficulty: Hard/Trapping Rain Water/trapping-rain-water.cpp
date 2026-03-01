class Solution {
  public:
    vector<int> leftMemo, rightMemo;
    int maxLeft(vector<int> &arr, int i) {
        if(i == 0) {
            return leftMemo[i] = arr[i];
        }
        
        if(leftMemo[i] != -1) {
            return leftMemo[i];
        }
        
        return leftMemo[i] = max(arr[i], maxLeft(arr, i - 1));
    }
    
    int maxRight(vector<int> &arr, int i) {
        if(i == arr.size() - 1) {
            return rightMemo[i] = arr[i];
        }
        
        if(rightMemo[i] != -1) {
            return rightMemo[i];
        }
        
        return rightMemo[i] = max(arr[i], maxRight(arr, i + 1));
    }
    
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        leftMemo.assign(n, -1), rightMemo.assign(n, -1);
        int water = 0;
        
        for(int i = 0; i < n; i++) {
            int leftMax = maxLeft(arr, i);
            int rightMax = maxRight(arr, i);
            
            water += min(leftMax, rightMax) - arr[i];
        }
        
        return water;
        
    }
};