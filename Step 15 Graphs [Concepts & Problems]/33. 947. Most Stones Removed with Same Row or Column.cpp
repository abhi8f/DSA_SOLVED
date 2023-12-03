// mine
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int ulp_u, int ulp_v) {
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u] + 1;
            size[ulp_u] = 0;
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v] + 1;
            size[ulp_v] = 0;
        }
    }

    void updateSize(int x) {
        size[x]++;
    }

    int getMostStonesRemoved() {
        int ans = 0;
        for(auto &x: size) {
            if (x==0) continue;
            ans += x-1;
        }
        return ans;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int xmx = INT_MIN;
        int ymx = INT_MIN;

        for(auto &stone: stones) {
            xmx = max(xmx, stone[0]);
            ymx = max(ymx, stone[1]);
        }

        DisjointSet ds(xmx + ymx + 2);

        for(auto &stone: stones) {
            int x = stone[0];
            int y = xmx + 1 + stone[1];

            int xup = ds.findUPar(x);
            int yup = ds.findUPar(y);

            if (xup == yup) {
                ds.updateSize(xup);
            }
            else {
                ds.unionBySize(xup, yup);
            }
        }

        return ds.getMostStonesRemoved();
    }
};

//striver
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};
