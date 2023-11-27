class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        for(auto &vec: edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        vector<int> ans(N, -1);
        queue<pair<int, int>> nodeDistQ;
        nodeDistQ.push({src, 0});

        while(!nodeDistQ.empty()) {
            int node = nodeDistQ.front().first;
            int dist = nodeDistQ.front().second;
            nodeDistQ.pop();

            if (ans[node]==-1) ans[node] = dist;

            for(int x: adj[node]) {
                if (ans[x]!=-1) continue;
                nodeDistQ.push({x, dist+1});
            }
        }
        return ans;
    }
};
