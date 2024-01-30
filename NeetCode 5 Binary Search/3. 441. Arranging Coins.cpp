class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            double mid = l + (r - l)/2;
            double sum = (mid * (mid + 1))/2;

            if (sum == n) return mid;
            if (n < sum) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
