class Solution {
    public: 
    void rotate(vector < vector < int >> & matrix) {
        int n = matrix.size(), level = 0;
        while (level < n / 2) {
            int curRowSize = n - 2 * level;
            // l,l          // +o
            // l,n-l-1      // +o
            // n-l-1,n-l-1  // -o
            // n-l-1,l      // -o
            for (int offSet = 0; offSet < curRowSize-1; offSet++) {
                int pre = matrix[n - level - 1 - offSet][level];
                swap(pre, matrix[level][level + offSet]);
                swap(pre, matrix[level+offSet][n - level - 1]);
                swap(pre, matrix[n-level-1][n-level-1-offSet]);
                swap(pre, matrix[n-level-1-offSet][level]);
                // return;
            }
            level++;
        }
    }
};

void rotateMatrix(vector<vector<int>> &mat, int n, int m) {
    int l=0;
    while(l<n/2 && l<m/2){
        int curRowSize = n - 2 * l;
        // l,l          // +o
        // l,n-l-1      // +o
        // n-l-1,n-l-1  // -o
        // n-l-1,l      // -o
        int val=mat[l+1][l];
        for(int i=l+1;i<n-l-1;i++) mat[i][l]=mat[i+1][l];
        for(int i=l;i<m-l-1;i++) mat[n-l-1][i]=mat[n-l-1][i+1];
        // return;
        for(int i=n-l-1;i>l;i--) mat[i][m-l-1]=mat[i-1][m-l-1];
        for(int i=m-l-1;i>l;i--) mat[l][i]=mat[l][i-1];
        mat[l][l]=val;
        l++;
    }
}

