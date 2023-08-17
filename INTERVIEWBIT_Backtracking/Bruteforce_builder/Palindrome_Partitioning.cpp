#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &A) {
    while (i < j)
        if (A[i++] != A[j--]) return false;
    return true;
}

void rec(int i, string &A, vector<string> &cur, vector<vector<string>> &ans) {
    int n = A.size();
    if (i == n) {
        ans.push_back(cur);
        return;
    }
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, A)) {
            cur.push_back(A.substr(i, j - i + 1));
            rec(j + 1, A, cur, ans);
            cur.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string A) {
    vector<vector<string>> ans;
    vector<string> cur;
    rec(0, A, cur, ans);
    return ans;
}

int main() {
    partition("aab");
    cout<<"hi"<<endl;
}