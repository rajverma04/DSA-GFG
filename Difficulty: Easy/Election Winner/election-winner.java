import java.util.*;

class Solution {
    public ArrayList<String> winner(String[] arr) {
        Map<String, Integer> mp = new HashMap<>();
        for(String name : arr) {
            if(mp.containsKey(name)) {
                mp.put(name, mp.get(name) + 1);
            } else {
                mp.put(name, 1);
            }
        }
        String winner = "";
        int mx = 0;
        for(String name : mp.keySet()) {
            int cnt = mp.get(name);
            
            if(cnt > mx) {
                mx = cnt;
                winner = name;
            } else if(cnt == mx && name.compareTo(winner) < 0) {
                winner = name;
            }
        }
        
        ArrayList<String> ans = new ArrayList<>();
        ans.add(winner);
        ans.add(String.valueOf(mx));
        
        return ans;
    }
}