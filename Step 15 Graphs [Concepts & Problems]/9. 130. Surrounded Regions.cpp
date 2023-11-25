class Solution {
private: 
    void markEdgeRegion(int i, int j, vector<vector<char>>& board, vector<vector<bool>> &edgeRegion) {
        const int m = board.size(), n = board[0].size();
        if ((i+1) < m && board[i+1][j]=='O' && edgeRegion[i+1][j]==false) {
            edgeRegion[i+1][j] = true;
            markEdgeRegion(i+1, j, board, edgeRegion);
        }
        if ((i-1)>=0 && board[i-1][j]=='O' && edgeRegion[i-1][j]==false){
            edgeRegion[i-1][j] = true;
            markEdgeRegion(i-1, j, board, edgeRegion);
        }
        if ((j+1) < n && board[i][j+1]=='O' && edgeRegion[i][j+1]==false) {
            edgeRegion[i][j+1] = true;
            markEdgeRegion(i, j+1, board, edgeRegion);
        }
        if ((j-1)>=0 && board[i][j-1]=='O' && edgeRegion[i][j-1]==false){
            edgeRegion[i][j-1] = true;
            markEdgeRegion(i, j-1, board, edgeRegion);
        }
        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size(), n = board[0].size();
        vector<vector<bool>> edgeRegion(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            if (board[i][0]=='O' && edgeRegion[i][0]==false){
                edgeRegion[i][0] = true;
                markEdgeRegion(i, 0, board, edgeRegion);
            }
            if (board[i][n-1]=='O' && edgeRegion[i][n-1]==false){
                edgeRegion[i][n-1] = true;
                markEdgeRegion(i, n-1, board, edgeRegion);
            }
        }
        for(int j=0; j<n; j++) {
            if (board[0][j]=='O' && edgeRegion[0][j]==false){
                edgeRegion[0][j] = true;
                markEdgeRegion(0, j, board, edgeRegion);
            }
            if (board[m-1][j]=='O' && edgeRegion[m-1][j]==false){
                edgeRegion[m-1][j] = true;
                markEdgeRegion(m-1, j, board, edgeRegion);
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (!edgeRegion[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
