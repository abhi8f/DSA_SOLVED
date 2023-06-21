#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.size(), col = text2.size();
        if (row == 0 || col == 0) return 0;
        vector<int> pre(col, 0), cur(col, 0);
        for (int j = 0; j < col; j++) pre[j] = text1[0] == text2[j] ? 1 : 0;
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++)
                cur[j] = text1[i] == text2[j] ? 1 + pre[j - 1] : max(pre[j], cur[j - 1]);
            pre = cur;
        }
        return pre[col - 1];
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}