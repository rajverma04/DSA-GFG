class Solution {
    int findFrequency(int arr[], int x) {
        // code here
        // int cnt = 0;
        // for(int n : arr) {
        //     if(n == x) {
        //         cnt++;
        //     }
        // }
        
        // return cnt;
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        for(int n : arr) {
            mp.put(n, mp.getOrDefault(n, 0) + 1);
        }
        if(mp.get(x) == null) {
            return 0;
        }
        return mp.get(x);
    }
}