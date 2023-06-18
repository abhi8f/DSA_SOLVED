// TC: O(>>>2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int w, vector<int> &profit, vector<int> &weight) {
    if (i<0) return 0;
    return max(r(i-1, w, profit, weight), w>=weight[i]?r(i, w-weight[i], profit, weight) + profit[i]:INT_MIN);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    return r(n-1, w, profit, weight);
}

int main() {
    return 0;
}