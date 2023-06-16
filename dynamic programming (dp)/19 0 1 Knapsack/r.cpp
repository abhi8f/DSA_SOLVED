// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int maxWeight, vector<int> &weight, vector<int> &value) {
    if (i < 0) return 0;
    return max(r(i - 1, maxWeight, weight, value), maxWeight>=weight[i]?r(i - 1, maxWeight - weight[i], weight, value) + value[i]:0);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return r(n - 1, maxWeight, weight, value);
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