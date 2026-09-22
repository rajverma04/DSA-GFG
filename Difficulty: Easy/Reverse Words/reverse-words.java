class Solution {
    public String reverseWords(String s) {
        // Code here
        Stack<String> st = new Stack<>();
        
        
        String[] str = s.split("\\.");
        for(String w : str) {
            if(!w.isEmpty()) {
                st.push(w);
            }
        }
        
        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty()) {
            ans.append(st.peek());
            st.pop();
            if(!st.isEmpty()) {
                ans.append(".");
            }
        }
        
        return ans.toString();
    }
}
