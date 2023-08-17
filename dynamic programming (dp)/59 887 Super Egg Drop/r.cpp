// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
#include "r.h"
using namespace std;

int rec(int k, int n){
    if (n<=0) return 0;
    if (n==1) return 1;
    if (k==1) return n;
    int ans=INT_MAX;
    for(int floor=1;floor<=n;floor++){
        int breaks=rec(k-1,floor-1);
        int notBreaks=rec(k,n-floor);
        ans=min(ans, 1+max(breaks,notBreaks));
    }
    return ans;
}

class Solution {
public:
    int superEggDrop(int k, int n) {
        return rec(k,n);
    }
};

class Solution {
public:
    int superEggDrop(int k, int n) {
        return rec(0,n-1,k);
    }
};