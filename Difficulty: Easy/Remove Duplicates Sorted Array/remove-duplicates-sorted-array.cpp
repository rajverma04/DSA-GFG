class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        
        int index = 1;
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] != arr[i - 1]) {
                arr[index] = arr[i];
                index++;
            } 
        }
        arr.resize(index);      // Removes elements from the end
        return arr;
    }
};