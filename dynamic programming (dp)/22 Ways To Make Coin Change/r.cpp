// TC: O(>>>2^n)
// SC: O(value)
#include <bits/stdc++.h>
using namespace std;

long r(int i, int value, int *a){
    if (i<0) return value==0?1:0;
    return r(i-1, value, a) + (value>=a[i]?r(i, value-a[i], a):0);
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    return r(n-1, value, denominations);
}

int main() {
    return 0;
}