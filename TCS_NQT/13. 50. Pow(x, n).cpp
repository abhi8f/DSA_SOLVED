class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double ans = 1;
        while (n) {
            if (n%2==0) {
                x *= x;
                n /= 2;
            } else {
                if (n > 0) {
                    ans *= x;
                    n--;
                } else {
                    ans /= x;
                    n++;
                }
            }
        }
        return ans;
    }
};
