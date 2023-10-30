void traverseMaze(int i, int j, int n, vector<vector<int>> &mat, vector<vector<bool>> &vis, string &cur, vector<string> &ans) {
    if (i<0 || j<0 || i==n || j==n || mat[i][j]==0 || vis[i][j]==true) return;
    if (i==(n-1) && j==(n-1)) {
        ans.push_back(cur);
        return;
    }
    vis[i][j]=true;

    cur.push_back('D');
    traverseMaze(i+1, j, n, mat, vis, cur, ans);
    cur.pop_back();

    cur.push_back('R');
    traverseMaze(i, j+1, n, mat, vis, cur, ans);
    cur.pop_back();

    cur.push_back('L');
    traverseMaze(i, j-1, n, mat, vis, cur, ans);
    cur.pop_back();

    cur.push_back('U');
    traverseMaze(i-1, j, n, mat, vis, cur, ans);
    cur.pop_back();

    vis[i][j]=false;
}

vector<string> ratMaze(vector<vector<int>> &mat) {
    string cur="";
    vector<string> ans;
    int n=mat.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    traverseMaze(0, 0, n, mat, vis, cur, ans);
    return ans;
}
