class Solution {
    public int secFrequent(String[] arr) {
        // code here
        
        if(arr == null || arr.length == 0) {
            return -1;
        }
        
        HashMap<String, Integer> mp = new HashMap<>();
        for(String str : arr) {
            if(mp.containsKey(str)) {
                mp.put(str, mp.get(str) + 1);
            } else {
                mp.put(str, 1);
            }
        }
        if(mp.size() < 2) {
            return -1;
        }
        
        int mx = Integer.MIN_VALUE;
        int scmx = Integer.MIN_VALUE;
        
        for(int cnt : mp.values()) {
            if(cnt > mx) {
                scmx = mx;
                mx = cnt;
            } else if(cnt > scmx && cnt < mx) {
                scmx = cnt;
            }
        }
        if(scmx == Integer.MIN_VALUE || scmx == mx) {
            return -1;
        }
         
        return scmx;
        
    }
}