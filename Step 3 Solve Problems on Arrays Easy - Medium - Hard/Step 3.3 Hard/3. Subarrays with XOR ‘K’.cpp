#include<bits/stdc++.h>

int subarraysWithSumK(vector<int> a, int b) {
    int ans = 0, curXor = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int x : a) {
        curXor ^= x;
        auto search = m.find(curXor ^ b);
        if (search != m.end())
            ans += search->second;
        m[curXor]++;
    }
    return ans;
}