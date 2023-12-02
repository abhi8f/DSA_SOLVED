class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &vec: flights) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, src, 0);

        while(!pq.empty()) {
            int stops = get<0>(pq.top());
            int node = get<1>(pq.top());
            int cost = get<2>(pq.top());
            pq.pop();

            if (stops > k) continue;

            for(auto &iter: adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                if (dist[adjNode] < (cost + edW)) continue;

                dist[adjNode] = cost + edW;
                pq.emplace(stops + 1, adjNode, dist[adjNode]);
            }
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};
