/// @brief Disjoint Set Uninon Data Structure (Union by size, no node is by default set)
class DSU {
    vector<int> parent;
    vector<int> size;
   public:
    /// @brief DSU Initialization with no node is set
    /// @param n number of nodes
    DSU(int n) {
        size.resize(n, 0);
        parent.resize(n, -1);
    }

	/// @brief makes given node as set
	/// @param x given node
	void makeSet(int x) {
		parent[x] = x;
        size[x] = 1;
	}

	/// @brief tells weather given node is set
	/// @param x given node
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
        x = findSet(x);
        y = findSet(y);

        if (x == y) {
            return;
        }

        if (size[x] < size[y]) {
            swap(x, y);
        }

        parent[y] = x;
        size[x] += size[y];

        return;
    }


    /// @brief returns size of given set
    /// @param x given set (any node in set)
    /// @return size of set
    int getSize(int x) {
        return size[findSet(x)];
    }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

class Solution {
private:
    int d2d1(const int &i, const int &j, const int &n) {
        return i*n + j;
    }

    void makeLands(vector<vector<int>>& grid, DSU &ds) {
        int n = grid.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    int nodeNum = d2d1(i, j, n);
                    ds.makeSet(nodeNum);

                    for(int neighbourIndex = 0; neighbourIndex < 4; neighbourIndex++) {
                        int in = i + dx[neighbourIndex];
                        int jn = j + dy[neighbourIndex];
                        int neighbourNodeNum = d2d1(in, jn, n);

                        if (in<0 || in==n || jn<0 || jn==n || !ds.isSet(neighbourNodeNum)) continue;

                        ds.unionSets(nodeNum, neighbourNodeNum);
                    }
                }
            }
        }
    }

    int neighbourSum(const int &i, const int &j, const int &n, const vector<vector<int>>& grid, DSU &ds) {
        map<int, int> mapSetSize;
        for(int neighbourIndex = 0; neighbourIndex < 4; neighbourIndex++) {
            int in = i + dx[neighbourIndex];
            int jn = j + dy[neighbourIndex];
            int nodeNum = d2d1(in, jn, n);

            if (in<0 || in==n || jn<0 || jn==n || grid[in][jn]==0) continue;

            mapSetSize[ds.findSet(nodeNum)] = ds.getSize(nodeNum);
        }

        int sum = 0;
        for(auto &ss: mapSetSize) {
            sum += ss.second;
        }
        return sum + 1;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        makeLands(grid, ds);

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == 0) {
                    ans = max(ans, neighbourSum(i, j, n, grid, ds));
                } else {
                    ans = max(ans, ds.getSize(d2d1(i, j, n)));
                }
            }
        }
        return ans;
    }
};
