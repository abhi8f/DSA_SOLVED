
class Solution {
    struct info {
        int x, y, dist;
        info(int x, int y, int dist): x(x), y(y), dist(dist) {};
    };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        queue<info> Q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (mat[i][j]==0) Q.push(info(i,j,0));
            }
        }

        while(!Q.empty()) {
            int x = Q.front().x;
            int y = Q.front().y;
            int dist = Q.front().dist + 1;
            Q.pop();

            if ((x+1) < m && mat[x+1][y]==1) {
                mat[x+1][y] = 0;
                ans[x+1][y] = dist;
                Q.push(info(x+1, y, dist));
            }
            if ((x-1)>=0 && mat[x-1][y]==1){
                mat[x-1][y] = 0;
                ans[x-1][y] = dist;
                Q.push(info(x-1, y, dist));
            }
            if ((y+1) < n && mat[x][y+1]==1) {
                mat[x][y+1] = 0;
                ans[x][y+1] = dist;
                Q.push(info(x, y+1, dist));
            }
            if ((y-1)>=0 && mat[x][y-1]==1){
                mat[x][y-1] = 0;
                ans[x][y-1] = dist;
                Q.push(info(x, y-1, dist));
            }
        }
        return ans;
    }
};
