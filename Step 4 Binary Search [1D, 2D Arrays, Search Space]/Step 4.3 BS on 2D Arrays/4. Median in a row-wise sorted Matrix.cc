#include<bits/stdc++.h>
using namespace std;

int getPreEqualByUpperBound(int num, vector<vector<int>> &mat, int m, int n) {
    int cnt = 0, low, high, mid;
    for(int i = 0; i < m; i++) {
        low = 0, high = n - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mat[i][mid] <= num) low = mid + 1;
            else high = mid - 1;
        }
        cnt += low;
    }
    return cnt;
}

int median(vector<vector<int>> &mat, int m, int n) {
    int leftPart = m * n / 2, low = INT_MAX, high = INT_MIN, mid, cnt;
    for(int i = 0; i < m; i++) low = min(low, mat[i][0]), high = max(high, mat[i][n-1]);

    while (low <= high) {
        mid = low + (high - low) / 2;
        cnt = getPreEqualByUpperBound(mid, mat, m, n);
        if (cnt <= leftPart) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {	
    int m, n;
    cin>>m>>n;
    vector<vector<int>> v(m, vector<int>(n));
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin>>v[i][j];
    cout<<median(v, m, n)<<endl;
    return 0;
}
