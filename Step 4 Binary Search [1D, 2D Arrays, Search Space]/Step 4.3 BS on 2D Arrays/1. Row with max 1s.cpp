int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int mO=0, mR=-1, low, high, mid, cur;
    for(int r=0; r<n; r++) {
        low = 0, high = m - 1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[r][mid] == 1) high = mid - 1;
            else low = mid + 1;
        }
        cur = m - low;
        if (cur > mO) mO = cur, mR = r;
    } 
    return mR;
}