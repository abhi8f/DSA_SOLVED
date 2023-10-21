class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size(), low = 0, high = cols - 1, mid, mr, l, r;

        while (low <= high) {
            mid = low + (high - low) / 2;
            mr=0;
            for(int i = 0; i < rows; i++) 
                if (mat[i][mid] > mat[mr][mid]) mr = i;

            l = mid!=0 ? mat[mr][mid - 1] : -1;
            r = mid!=(cols - 1) ? mat[mr][mid + 1] : -1;

            if (mat[mr][mid] > max(l, r)) return {mr, mid};
            if (l > r) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};