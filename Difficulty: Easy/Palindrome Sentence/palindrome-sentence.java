class Solution {
    public boolean isPalinSent(String s) {
        // code here
        StringBuffer str = new StringBuffer("");
        for(char ch : s.toCharArray()) {
            if(Character.isLetter(ch) || Character.isDigit(ch)) {
                str.append(Character.toLowerCase(ch));
            }
        }
        
        int i = 0, j = str.length() - 1;
        // str = str.toLowerCase();
        while(i < j) {
            if(str.charAt(i) != str.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
}