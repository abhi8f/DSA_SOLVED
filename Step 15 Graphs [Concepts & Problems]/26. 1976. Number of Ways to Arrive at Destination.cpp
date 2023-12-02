class Solution {
    static const int MBY = (int)(1e9 + 7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto &road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long> dist(n, LONG_MAX);
        dist[0] = 0;
        vector<long> count(n, 0);
        count[0] = 1;

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.emplace(0, 0);

        while(!pq.empty()) {
            long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &item: adj[node]) {
                int adjNode = item.first;
                long adjDis = item.second;

                if (dist[adjNode]>(dis+adjDis)){
                    count[adjNode]=count[node];
                    dist[adjNode] = dis + adjDis;
                    pq.emplace(dist[adjNode], adjNode);
                }
                else if (dist[adjNode]==(dis+adjDis)) {
                    count[adjNode] = (count[adjNode]+count[node])%MBY;
                }
            }
        }
        return count[n-1]%MBY;
    }
};
