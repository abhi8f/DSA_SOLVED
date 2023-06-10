//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   private:
    bool dfs(int node, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        // visit adjacent nodes
        for (auto adjacentNode : adj[node]) {
            // unvisited adjacent node
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, vis, adj) == true)
                    return true;
            } else
                return true;
        }
        return false;
    }

   public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> adjr[V];
        int E=sizeof(adj)/sizeof(adj[0]);
        for(int i=0;i<E;i++){
            adjr[adj[i][0]].push_back(adj[i][1]);
        }
        int vis[V] = {0};
        // for graph with connected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, adjr) == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    /*
    6 5
5 3
3 1
1 2
2 4
4 0
    */
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}