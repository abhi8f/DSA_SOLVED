// User function Template for C++

class DSU {
    vector<int> rank;
    vector<int> parent;

   public:
    /// @brief DSU Initialization
    /// @param n number of nodes
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n, -1);
    }

    void makeSet(int x) {
        parent[x] = x;
    }
    bool isSet(int x) {
        return parent[x]!=-1;
    }

    /// @brief finds set which set x belongs (represented in terms of root node)
    /// @param x any node in set
    /// @return the set x belongs
    int findSet(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findSet(parent[x]);
    }

    /// @brief Does union of two sets (if sets are different)
    /// @param x first set (any node in set1)
    /// @param y second set (any node in set2)
    void unionSets(int x, int y) {
        int xset = findSet(x);
        int yset = findSet(y);

        if (xset == yset) return;

        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        DSU ds(n*m);
        int totalIslands = 0;
        vector<int> ans;

        for(auto &land: operators) {
            int i = land[0];
            int j = land[1];
            int d1 = i * m + j;
            if (!ds.isSet(d1)) {
                ds.makeSet(d1);
                totalIslands++;
            }

            for(int a=0; a<4; a++) {
                int ii = i + dx[a];
                int jj = j + dy[a];
                int dd1 = ii*m+jj;

                if (ii<0 || ii==n || jj<0 || jj==m || !ds.isSet(dd1) || (ds.findSet(d1) == ds.findSet(dd1))) continue;

                ds.unionSets(d1, ii*m+jj);
                totalIslands--;
            }

            ans.push_back(totalIslands);

        }
        return ans;
    }
};
