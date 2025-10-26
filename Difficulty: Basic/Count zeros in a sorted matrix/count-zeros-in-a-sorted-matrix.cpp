//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>> A) {
        // code here
        int count = 0;
        int row = A.size(), col = A[0].size();
        int i = 0, j = col - 1;
        
        while(i < row && j >= 0) {
            while(j >= 0 && A[i][j] == 1) {     // until j >= 0 && if a[i][j] == 1 keep moving left for zero
                j--;
            }
            count += j + 1;
            i++;
        }
        
        return count;
    }
};