// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.empty()) {
            return "";
        }
        int count = 0;
        int minCol = INT_MAX;
        for(int i = 0; i < arr.size(); i++) {       // to get the size of min length of string
            if(minCol > arr[i].size()) {
                minCol = arr[i].size();
            }
        }
        
        for(int col = 0; col < minCol; col++) {
            char currentChar = arr[0][col];     // 
            for(int row = 1; row < arr.size(); row++) {
                if(arr[row][col] != currentChar) {
                    return arr[0].substr(0, count);
                }
            }
            count++;
        }
        
        return arr[0].substr(0, count);
        
        
    }
};