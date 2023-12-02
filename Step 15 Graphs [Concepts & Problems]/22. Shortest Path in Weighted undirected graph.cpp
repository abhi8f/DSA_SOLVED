
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &vec: edges) {
            adj[vec[0]-1].push_back({vec[1]-1, vec[2]});
            adj[vec[1]-1].push_back({vec[0]-1, vec[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i]=i;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // if (dis>dist[node]) continue;

            for(auto &item: adj[node]) {
                int adjNode = item.first;
                int adjDis = item.second;
                if (dis + adjDis < dist[adjNode]){
                    dist[adjNode] = dis + adjDis;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if (dist[n-1]==INT_MAX) return {-1};

        vector<int> ans;
        int node = n-1;
        while(parent[node]!=node) {
            ans.push_back(node+1);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
