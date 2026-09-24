class Solution {
    ArrayList<Integer> removeDuplicates(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>();
        Set<Integer> st = new LinkedHashSet<>();
        
        for(int x : arr) {
            st.add(x);
        }
        for(int v : st) {
            ans.add(v);
        }
        
        return ans;
        
    }
}
