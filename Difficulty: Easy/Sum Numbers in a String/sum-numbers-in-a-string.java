class Solution {
    public static int findSum(String s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            int num = 0;
            while(i < s.length() && Character.isDigit(s.charAt(i))) {
                num = num * 10 + (s.charAt(i) - '0');
                i++;
            }
            sum += num;
            
        }
        
        return sum;
        
    }
}