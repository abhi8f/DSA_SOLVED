// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    double dfs(int i, int t, int target, vector<int> g[], vector<bool>& vis) {
        if (t==0) return i == target;
        vis[i] = true;
        double ans = 0;
        int cnt = 0;
        for (auto& j : g[i]) {
            if (!vis[j]) {
                ans += dfs(j, t - 1, target, g, vis);
                cnt++;
            }
        }
        if (cnt == 0) return i == target;
        return ans / cnt;
    }

   public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> g[n];
        for (auto& e : edges) {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
        }
        vector<bool> vis(n, false);
        return dfs(0, t, target - 1, g, vis);
    }
};

int main() {
    Solution sol = Solution();
    int n = 7, t = 20, target = 6;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
    cout << sol.frogPosition(n, edges, t, target) << endl;
    return 0;
}