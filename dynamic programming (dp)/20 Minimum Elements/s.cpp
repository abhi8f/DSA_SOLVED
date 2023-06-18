// TC: O(n*x)
// SC: O(x)
#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vector<int> cur(x + 1, 1e8);
    cur[0] = 0;
    for (int j=num[0]; j<=x; j+=num[0]) cur[j] = j/num[0];

    for(int i=1;i<n;i++)
        for(int j=0;j<=x;j++)
            cur[j] = min(cur[j], j>=num[i] ? cur[j-num[i]]+1 : (int)1e8);
    
    return cur[x] == 1e8 ? -1 : cur[x];
}

int main() {
    /*
3 7
1 2 3

    */
    int n = 3, x = 7;
    vector<int> num = {1, 2, 3};
    cout << minimumElements(num, x);
    return 0;
}