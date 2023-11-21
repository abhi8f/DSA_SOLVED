class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        int oldColor = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int, int>> coloredQueue;
        coloredQueue.push({sr, sc});

        int x, y, m = image.size(), n = image[0].size();
        while (!coloredQueue.empty()) {
            x = coloredQueue.front().first;
            y = coloredQueue.front().second;
            coloredQueue.pop();

            if ((x+1) < m && image[x+1][y]==oldColor) {
                image[x+1][y] = color;
                coloredQueue.push({x+1, y});
            }
            if ((x-1)>=0 && image[x-1][y]==oldColor){
                image[x-1][y] = color;
                coloredQueue.push({x-1, y});
            }
            if ((y+1) < n && image[x][y+1]==oldColor) {
                image[x][y+1] = color;
                coloredQueue.push({x, y+1});
            }
            if ((y-1)>=0 && image[x][y-1]==oldColor){
                image[x][y-1] = color;
                coloredQueue.push({x, y-1});
            }
        }
        return image;
    }
};
