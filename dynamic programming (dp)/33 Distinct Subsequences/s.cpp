// TC: O(m*n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<long long> pre(ls, 0), cur(ls, 0);
    pre[0] = (t[0] == s[0]);

    for (long long i = 1; i < lt; i++) {
        cur[0] = pre[0] + (t[i] == s[0]);
        for (long long j = 1; j < ls; j++)
            cur[j] = pre[j] + (t[i] == s[j] ? pre[j - 1] : 0);

        swap(pre, cur);
    }

    return pre[ls - 1];
}

class Solution {
   public:
    int numDistinct(string s, string t) {
        long long ls = s.size(), lt = t.size();
        if (ls<lt) return 0;
        if (ls==lt) return s==t;
        vector<long long> pre(lt, 0), cur(lt, 0);
        pre[0] = (t[0] == s[0]);

        for (long long i = 1; i < ls; i++) {
            cur[0] = pre[0] + (s[i] == t[0]);
            for (long long j = 1; j < lt; j++)
                cur[j] = pre[j] + (s[i] == t[j] ? pre[j - 1] : 0);

            swap(pre, cur);
        }

        return pre[lt - 1];
    }
};

int main() {
    /*
    10 3
    brootgroot
    brt
    */
    int lt = 10, ls = 3;
    string t = "brootgroot", s = "brt";
    cout << subsequenceCounting(t, s, lt, ls) << endl;
    return 0;
}