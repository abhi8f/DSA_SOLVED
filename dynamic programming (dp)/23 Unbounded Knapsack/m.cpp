// TC: O(n*w)
// SC: O(n) + O(n*w) = O(n*w)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &mv) {
    if (i<0) return 0;
    if (mv[i][w]!=-1) return mv[i][w];
    return mv[i][w] = max(r(i-1, w, profit, weight, mv), w>=weight[i]?r(i, w-weight[i], profit, weight, mv) + profit[i]:INT_MIN);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> mv(n, vector<int>(w+1, -1));
    return r(n-1, w, profit, weight, mv);
}

int main() {
    return 0;
}