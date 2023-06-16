// TC: O(n*maxWeight)
// SC: O(2*maxWeight) = O(maxWeight)
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> cur(maxWeight + 1, 0);

    for (int j = weight[0]; j <= maxWeight; j++) cur[j] = value[0];

    for (int i = 1; i < n; i++)
        for (int j = maxWeight; j >= 0; j--)
            cur[j] = max(cur[j], j >= weight[i] ? cur[j - weight[i]] + value[i] : 0);

    return cur[maxWeight];
}

int main() {
    /*
7
1 5 6 9 7 9 7
1 7 1 5 1 7 7
37
    */
    int n = 7;
    vector<int> weight = {1, 5, 6, 9, 7, 9, 7};
    vector<int> value = {1, 7, 1, 5, 1, 7, 7};
    int maxWeight = 37;
    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}