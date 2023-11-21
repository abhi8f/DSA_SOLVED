const int dax[] = {-1, 1, 0, 0};
const int day[] = {0, 0, -1, 1};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> rottenQueue;
        int fresh=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j]==2) rottenQueue.push({i, j});
                else if (grid[i][j]==1) fresh++;
            }
        }
        if (rottenQueue.empty()) return fresh==0? 0: -1;

        int time = -1;
        int s;
        while (!rottenQueue.empty()) {
            time++;
            s = rottenQueue.size();
            
            int x, y, xx, yy;
            while(s--) {
                x = rottenQueue.front().first;
                y = rottenQueue.front().second;
                rottenQueue.pop();

                for(int i = 0; i<4; i++) {
                    xx = x + dax[i];
                    yy = y + day[i];

                    if (xx<0 || xx==m || yy<0 || yy==n || grid[xx][yy]==0 || grid[xx][yy]==2) continue;
                    fresh--;
                    grid[xx][yy]=2;
                    rottenQueue.push({xx,yy});
                }

                cout<<endl;
            }
        }
        if (fresh==0)
            return time;
        return -1;
    }
};
