class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for (auto &edge : edges) {
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; i++) mat[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        int city = INT_MIN, cityNeighbour = INT_MAX;

        for (int i = 0; i < n; i++) {
            int curNeighbour = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (mat[i][j] <= distanceThreshold) curNeighbour++;
            }

            if (curNeighbour <= cityNeighbour) {
                cityNeighbour = curNeighbour;
                city = i;
            }
        }

        return city;
    }
};
