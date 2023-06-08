#include <bits/stdc++.h>
using namespace std;

bool f(int V, vector<int> al[]) {
    bool vv[V] = {false};

    
    for(int i=0;i<V;i++){
        if (vv[i]) continue;

        int vp[V]={-1};
        vv[i] = true;
        queue<int> q;
        q.push(i);
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
    }
    return false;
}

void addEdge(vector<int> al[], int u, int v) {
    al[u].push_back(v);
    al[v].push_back(u);
}

int main() {
    vector<int> al[8];

    addEdge(al, 0, 1);
    addEdge(al, 1, 2);
    addEdge(al, 1, 3);
    addEdge(al, 0, 4);
    addEdge(al,4,5);
    addEdge(al,5,6);
    addEdge(al,6,4);
    // addEdge(al,3,4);



    
    cout<< f(7,al)<<endl;

    return 0;
}