class Solution {
private:
    void dfs(int i, vector<int> adj[], vector<bool> &vis, vector<int> &ans) {
        ans.push_back(i);
        vis[i] = true;
        for(int n: adj[i]) {
            if (vis[n]) continue;
            dfs(n, adj, vis,ans);
        }
        return;
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if (!vis[i]) dfs(i, adj, vis, ans);
        }
        return ans;
    }
};
