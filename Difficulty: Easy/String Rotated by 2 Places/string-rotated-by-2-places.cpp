class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        
        // clockwise rotation
        bool clockwise = true;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[(i + 2) % s2.size()]) {
                clockwise = false;
                break;
            }
        }
        
        // anticlockwise rotation
        bool anticlockwise = true;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[(i + 2) % s1.size()] != s2[i]) {
                anticlockwise = false;
                break;
            }
        }
        
        return clockwise || anticlockwise;
    }
};
