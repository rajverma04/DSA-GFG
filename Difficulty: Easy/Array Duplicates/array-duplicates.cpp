class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        vector<int> ans;
        // M1   
        
        //     for(int i = 0; i < size - 1; i++) {
        //         for(int j = i + 1; j < size; j++) {
        //             if(!(arr[i] ^ arr[j])) {       // if duplicate present , T(O) = n^2
        //                 ans.push_back(arr[i]);
        //             } else {
        //                 continue;
        //             }
        //         }
        //     }
        
        // return ans;
    
        // M2 : Frequency method
        // vector<int> freq(size + 1, 0);
        // for(int i = 0; i < size; i++) {
        //     freq[arr[i]]++;     // accessing the index of element value
        //     if(freq[arr[i]] == 2) {     // if freq. count == 2 means duplicate present
        //         ans.push_back(arr[i]);      // storing the duplicate occur atleast 2 times
        //     }
        // }
        
        // M3
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                ans.push_back(arr[i]);
                // Skip all consecutive duplicates of the same number
                while(i < arr.size() && arr[i] == arr[i + 1]) {
                    i++;
                }
            }
        }
        return ans;
    }
};