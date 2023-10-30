class Solution {
private:
    void placeNQueens(short col, short n, vector<bool> &leftRow, vector<bool> &lowerDiag, vector<bool> &upperDiag, vector<string> &cur, vector<vector<string>> &ans) {
        if (col==n) {
            ans.push_back(cur);
            return;
        }
        for(short row=0; row<n; row++) {
            if (leftRow[row] || lowerDiag[row+col] || upperDiag[n-1+col-row]) continue;
            leftRow[row]=lowerDiag[row+col]=upperDiag[n-1+col-row]=true;
            cur[row][col]='Q';
            placeNQueens(col+1, n, leftRow, lowerDiag, upperDiag, cur, ans);
            leftRow[row]=lowerDiag[row+col]=upperDiag[n-1+col-row]=false;
            cur[row][col]='.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> cur(n, s);
        vector<vector<string>> ans;
        vector<bool> leftRow(n, false), lowerDiag(2*n-1, false), upperDiag(2*n-1, false);
        placeNQueens(0, n, leftRow, lowerDiag, upperDiag, cur, ans);
        return ans;
    }
};
