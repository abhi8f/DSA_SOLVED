class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while (l <= r) {
            double m = l + (r - l)/2;
            double sq = m*m;

            if (sq == x) {
                return m;
            } else if (sq < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};
