const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({dist[0][0], {0, 0}});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(int a=0; a<4; a++) {
                int ni = i + dr[a];
                int nj = j + dc[a];

                if (ni<0 || ni==rows || nj<0 || nj==cols) continue;
                if (dist[ni][nj]<=max(dis, abs(heights[i][j]-heights[ni][nj]))) continue;

                dist[ni][nj] = max(dis, abs(heights[i][j]-heights[ni][nj]));
                pq.push({dist[ni][nj], {ni, nj}});
            }
        }

        return dist[rows-1][cols-1];
    }
};
