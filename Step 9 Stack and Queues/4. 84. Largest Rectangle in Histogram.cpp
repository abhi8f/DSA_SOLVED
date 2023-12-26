class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1); // some remain till end, to remove them
        int n = heights.size();
        stack<pair<int, int>> startHeight;
        int ans = 0;

        for(int i=0; i<n; i++) {
            int startBig = i;
            int heightBig;
            while(!startHeight.empty() && (startHeight.top().second > heights[i])) {
                startBig = startHeight.top().first;
                heightBig = startHeight.top().second;
                startHeight.pop();
                ans = max(ans, heightBig * (i - startBig));
            }
            startHeight.push({startBig, heights[i]});
        }
        return ans;
    }
};
