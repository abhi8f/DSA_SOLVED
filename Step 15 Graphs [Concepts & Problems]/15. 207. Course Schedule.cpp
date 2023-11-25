class Solution {
private:
    bool hasCycle(int i, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &adj) {
        vis[i] = true;
        pathVis[i] = true;

        for(int &j: adj[i]) {
            if (!vis[j] && hasCycle(j, vis, pathVis, adj)) return true;

            if (pathVis[j]) return true;
        }
        pathVis[i] = false;
        return false;
    }

public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);

        for(auto &vec: prerequisites) {
            adj[vec[0]].push_back(vec[1]);
        }

        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);

        for(int i=0; i<V; i++) {
            if (!vis[i] && hasCycle(i, vis, pathVis, adj)) return false; 
        }
        return true;
    }
};
