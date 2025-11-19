class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        stack<int> s1;
        
        int middle = s.size() / 2;
        
        while(middle != 0) {
            int num = s.top();
            s.pop();
            s1.push(num);
            middle--;
        }
        s.pop();
        
        while(s1.size() != 0) {
            int num = s1.top();
            s1.pop();
            s.push(num);
        }
    }
};