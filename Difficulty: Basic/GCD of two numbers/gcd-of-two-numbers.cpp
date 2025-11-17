class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        return (b == 0) ? abs(a) : gcd(b, a % b);
    }
};
