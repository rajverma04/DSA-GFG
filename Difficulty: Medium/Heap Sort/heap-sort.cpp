// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    void heapify(vector<int> &maxHeap, int size, int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if(left < size && maxHeap[left] > maxHeap[largest]) {       // if left element is greate than parent
            largest = left;
        }
        
        if(right < size && maxHeap[right] > maxHeap[largest]) {
            largest = right;
        }
        
        
        if(largest != index) {
            swap(maxHeap[largest], maxHeap[index]);
            heapify(maxHeap, size, largest);
        }
    }
    
    
    
    void heapSort(vector<int>& arr) {
        // create maxHeap
        for(int i = arr.size() / 2 - 1; i >= 0; i--) {
            heapify(arr, arr.size(), i);
        }
        // sorting
        for(int i = arr.size() - 1; i >= 0; i--) {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
        
    }
};