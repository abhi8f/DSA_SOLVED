class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int numAccounts = accounts.size();
        DisjointSet ds(numAccounts);

        unordered_map<string, int> mapAccountUser;

        for(int i=0; i<numAccounts; i++) {
            int numEmails = accounts[i].size();
            for(int j = 1; j<numEmails; j++) {
                auto search = mapAccountUser.find(accounts[i][j]);
                if (search != mapAccountUser.end()) {
                    ds.unionByRank(search->second, i);
                } else {
                    mapAccountUser[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> mergeMail(numAccounts);

        for(auto &item: mapAccountUser) {
            int ulPar = ds.findUPar(item.second);
            mergeMail[ulPar].push_back(item.first);
        }

        vector<vector<string>> ans;

        for(int i=0; i<numAccounts; i++) {
            if (mergeMail[i].size()==0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergeMail[i].begin(), mergeMail[i].end());
            temp.insert(temp.end(), mergeMail[i].begin(), mergeMail[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};
