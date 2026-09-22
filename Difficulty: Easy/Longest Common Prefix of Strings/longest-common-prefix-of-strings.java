class Solution {
    public String longestCommonPrefix(String arr[]) {
        // code here
        String s = "";
        int idx = 0;
        for(int i = 1; i < arr.length; i++) {
            if(arr[i].length() < arr[idx].length()) {
                idx = i;
            }
        }
        
        String ans = arr[idx];
        for(int i = 0; i < arr.length; i++) {
            int j = 0;
            
            while(j < ans.length() && j < arr[i].length() && ans.charAt(j) == arr[i].charAt(j)) {
                j++;
            }
            ans = ans.substring(0, j);
            if(ans.isEmpty()) {
                return "";
            }
        }
        
        return ans;
        
    }
}