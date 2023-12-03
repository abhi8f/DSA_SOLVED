
class DisjointSet {
    vector<int> rank;
    vector<int> parent;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int getUPar(int x) {
        if (parent[x] == x) return x;

        return parent[x] = getUPar(parent[x]);
    }

    void unite(int u, int v) {
        int upU = getUPar(u);
        int upV = getUPar(v);

        if (rank[upU] < rank[upV]) {
            parent[upU] = upV;
        } else if (rank[upV] < rank[upU]) {
            parent[upV] = upU;
        } else {
            parent[upU] = upV;
            rank[upU]++;
        }
    }
};

class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<tuple<int, int, int>> edges;

        for(int i=0; i<V; i++) {
            for(auto &p: adj[i]) {
                edges.push_back(tuple<int, int, int>(p[1], i, p[0]));
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        int ans = 0;

        for(auto &t: edges) {
            int wt = get<0>(t);
            int u = get<1>(t);
            int v = get<2>(t);

            if (ds.getUPar(u)==ds.getUPar(v)) continue;

            ds.unite(u, v);
            ans += wt;
        }
        return ans;

    }
};
