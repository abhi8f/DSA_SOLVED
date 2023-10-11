#include<bits/stdc++.h>

unsigned long getPow(long long e, int &n, int &m) {
    if (e == 0) return 1;

    long long part = getPow(e / 2, n, m);
    if (part > m) return part;

    part *= part;
    if (e % 2 == 1) part *= n;
    return part;
}

int NthRoot(int n, int m) {
    int l = 0, h = m, mid;
    unsigned long p;
    while (l <= h) {
        mid = l + (h - l) / 2;
        p = getPow(n, mid, m);
        if (p == m)
            return mid;
        else if (p > m)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
