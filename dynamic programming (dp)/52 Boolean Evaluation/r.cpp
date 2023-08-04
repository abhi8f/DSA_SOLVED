// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;

int rec(int l, int r, bool isTrue, string &exp) {
    if (l == r) return isTrue == true ? exp[l] == 'T' : exp[l] == 'F';
    int ans = 0;
    long long lt,lf,rt,rf,cur;
    for (int p = l + 1; p <= r - 1; p += 2) {
        lt = rec(l, p - 1, true, exp);
        lf = rec(l, p - 1, false, exp);
        rt = rec(p + 1, r, true, exp);
        rf = rec(p + 1, r, false, exp);
        cur = 0;
        if (exp[p] == '&')
            cur = isTrue ? lt * rt
                         : lf * rf + lt * rf + lf * rt;
        else if (exp[p] == '|')
            cur = isTrue ? lt * rt + lt * rf + lf * rt
                         : lf * rf;
        else if (exp[p] == '^')
            cur = isTrue ? lt * rf + lf * rt
                         : lt * rt + lf * rf;
        ans+=(int)(cur%1000000007);
    }
    return ans;
}
int evaluateExp(string &exp) {
    return rec(0, exp.size() - 1,true, exp);
}

int main() {
    string s = "T^T|F|T";
    cout << evaluateExp(s) << endl;
    return 0;
}