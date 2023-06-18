// TC: O(n*w)
// SC: O(w)
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> cur(w+1, 0);
    for (int j=weight[0]; j<=w; j++) cur[j] = j/weight[0]*profit[0];
    for (int i=1; i<n; i++) 
        for (int j=1; j<=w; j++) 
            cur[j] = max(cur[j], j>=weight[i]?cur[j-weight[i]]+profit[i]:INT_MIN);
        
    return cur[w];
}

int main() {
    return 0;
}