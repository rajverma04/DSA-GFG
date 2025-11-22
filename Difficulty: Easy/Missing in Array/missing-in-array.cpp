class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // M1: sum of n natural number
        long long n = (long long)arr.size() + 1;         // actual size if number is not missing 
        long long sum = n * (n + 1) / 2;      // sum of n natural number
        long long arrSum = 0;                 // given array sum
        
        for(int i = 0; i < arr.size(); i++){
            arrSum += arr[i];
        }
        
        return (int)(sum - arrSum);          // difference btw actual and given sum is the missing number
        
       
    }
};