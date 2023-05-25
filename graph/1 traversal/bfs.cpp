#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> al[]) {
    int vv[V] = {0};
    vv[0] = 1;
    queue<int> q;

    q.push(0);
    vector<int> bfs;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : al[node]) {
            if (!vv[it]) {
                vv[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void addEdge(vector<int> al[], int u, int v) {
    al[u].push_back(v);
    al[v].push_back(u);
}

void printVector(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout<<endl;
}

int main() {
    vector<int> al[6];

    addEdge(al, 0, 1);
    addEdge(al, 1, 2);
    addEdge(al, 1, 3);
    addEdge(al, 0, 4);

    
    vector<int> ans = bfs(5, al);
    printVector(ans);

    return 0;
}