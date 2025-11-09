class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        
        if(low >= high) {
            return;
        }
        
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
            
    }


  public:
    int partition(vector<int>& arr, int low, int high) {
        
        int pos = low;
        
        for(int i = low; i <= high; i++) {
            if(arr[high] >= arr[i]) {
                swap(arr[i], arr[pos++]);
            }
        }
        return pos - 1;
        
    }
};