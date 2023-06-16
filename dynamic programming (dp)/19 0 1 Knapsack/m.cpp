// TC: O(n*maxWeight)
// SC: O(n) + O(n*maxWeight) = O(n*maxWeight)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &mv) {
    if (i < 0) return 0;
    if (mv[i][maxWeight] != -1) return mv[i][maxWeight];
    return mv[i][maxWeight] = max(r(i - 1, maxWeight, weight, value, mv), maxWeight>=weight[i]?r(i - 1, maxWeight - weight[i], weight, value, mv) + value[i]:0);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> mv(n, vector<int>(maxWeight + 1, -1));
    return r(n - 1, maxWeight, weight, value, mv);
}

int main() {
    /*
7
1 5 6 9 7 9 7 
1 7 1 5 1 7 7 
37
    */
    int n=7;
    vector<int> weight={1, 5, 6, 9, 7, 9, 7};
    vector<int> value={1, 7, 1, 5, 1, 7, 7};
    int maxWeight=37;
    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}