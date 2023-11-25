class Solution {
private:
    bool canColorDFS(int i, int c, vector<int8_t> &color, vector<vector<int>>& adj) {
        if (color[i]!=-1 && color[i]!=c) return false;
        if (color[i]==c) return true;
        color[i] = c;
        for(int x: adj[i]) {
            if (!canColorDFS(x, !c, color, adj)) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int8_t> color(V, -1);

        for(int i=0; i<V; i++) {
            if (color[i]!=-1) continue;

            if (!canColorDFS(i, 0, color, adj)) return false;
        }
        return true;
    }
};
