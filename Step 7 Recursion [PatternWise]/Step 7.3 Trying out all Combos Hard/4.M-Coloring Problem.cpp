bool isSafe(int c, int i, int v, vector<int> &colored, vector<vector<int>> &mat) {
    for(int j=0; j<v; j++) {
        if (mat[i][j]==1 && colored[j]==c) {
            return false;
        }
    }
    return true;
}

bool canColor(int i, int v, int m, vector<int> &colored, vector<vector<int>> &mat) {
    if (i==v) return true;
    
    for(int c=1; c<=m; c++) {
        if (!isSafe(c, i, v, colored, mat)) continue;
        colored[i]=c;
        if (canColor(i+1, v, m, colored, mat)) return true;
        colored[i]=-1;
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int v = mat.size();
    vector<int> colored(v, -1);
    return canColor(0, v, m, colored, mat)?"YES":"NO";
}
