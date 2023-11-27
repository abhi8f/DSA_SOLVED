class Solution {
private: 
    void topoDFS(int i, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, stack<int> &topoStack) {
        vis[i] = true;
        for(auto &p: adj[i]) {
            if (!vis[p.first])
                topoDFS(p.first, adj, vis, topoStack);
        }
        topoStack.push(i);
        return;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        
        for(auto &vec: edges) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        
        stack<int> topoStack;
        vector<bool> vis(N, false);
        topoDFS(0, adj, vis, topoStack);
        
        vector<int> ans(N, INT_MAX);
        ans[0] = 0;
        
        while(!topoStack.empty()) {
            int node = topoStack.top();
            topoStack.pop();
            
            for(auto &p: adj[node]){
                ans[p.first] = min(ans[p.first], ans[node]+p.second);
            }
        }
        for(auto &x: ans) if (x==INT_MAX) x=-1;
        return ans;
    }
};
