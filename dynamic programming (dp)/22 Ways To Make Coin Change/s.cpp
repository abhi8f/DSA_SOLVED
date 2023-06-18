// TC: O(n*target)
// SC: O(n*target)
#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<long> cur(value+1, 0);
    cur[0] = 1;
    for (int j=denominations[0]; j<=value; j+=denominations[0]) cur[j] = 1;
    for (int i=1; i<n; i++){
        for (int j=1; j<=value; j++){
            cur[j] = cur[j] + (j>=denominations[i]?cur[j-denominations[i]]:0);
        }
    }
    return cur[value];
}

int main() {
/*
1 2 3
4
*/
    int n=3, value=4;
    int denominations[n] = {1, 2, 3};
    cout << countWaysToMakeChange(denominations, n, value) << endl;
    return 0;
}