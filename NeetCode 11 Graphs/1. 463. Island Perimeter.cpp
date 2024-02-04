int ix[] = {-1, +1, 0, 0};
int jx[] = {0, 0, -1, +1};

class Solution {

public:
    int countOutOfBounds(int i, int j, vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        if ((i < 0) || (i == r) || (j < 0) || (j == c)) return 1;
        if (grid[i][j] == 2) return 0;
        if (grid[i][j] == 0) return 1;

        grid[i][j] = 2;

        int ans = 0;
        for (int x = 0; x < 4; x++) {
            ans += countOutOfBounds(i + ix[x], j + jx[x], grid);
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) return countOutOfBounds(i, j, grid);
            }
        }
        return 0;
    }
};
