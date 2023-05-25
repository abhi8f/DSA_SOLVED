#include <bits/stdc++.h>
using namespace std;

bool f(int V, vector<int> al[]) {
    bool vv[V] = {false};
    int vp[V]={-1};
    vv[0] = true;
    queue<int> q;

    q.push(0);

    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : al[node]) {
            if (!vv[it]) {
                vv[it] = true;
                q.push(it);
                vp[it]=node;
            }
            else if (vp[node]!=it) return true;
        }
    }
    return false;
}

void addEdge(vector<int> al[], int u, int v) {
    al[u].push_back(v);
    al[v].push_back(u);
}

int main() {
    vector<int> al[6];

    addEdge(al, 0, 1);
    addEdge(al, 1, 2);
    addEdge(al, 1, 3);
    addEdge(al, 0, 4);
    // addEdge(al,3,4);

    
    cout<< f(6,al)<<endl;

    return 0;
}