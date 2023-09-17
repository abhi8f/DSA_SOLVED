class Solution {
   public:
    int reverse(int x) {
        int n1 = 214748364, n2 = -214748364;
        int res = 0;
        while (x) {
            int r = x % 10;
            if (x > 0) {
                if (res > n1) return 0;
                if ((res == n1) && (r > 7)) return 0;
            } else {
                if (res < n2) return 0;
                if ((res == n2) && (r < -8)) return 0;
            }
            x /= 10;
            res = res * 10 + r;
        }
        return res;
    }
};

#include<bits/stdc++.h>
long reverseBits(long n) {
    bitset<32> bs(n);
    for(int i=0;i<16;i++){
        if ((bs.test(i) && !bs.test(31-i)) ||
            (!bs.test(i) && bs.test(31-i)) ){
            bs.flip(i);
            bs.flip(31-i);
        }
    }
    return bs.to_ulong();
}

