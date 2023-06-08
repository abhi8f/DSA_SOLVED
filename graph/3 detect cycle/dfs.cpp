#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> al[], int vv[], vector<int> &ls) {
    vv[node] = 1;
    ls.push_back(node);

    for (auto it : al[node]) {
        if (!vv[it]) {
            dfs(it, al, vv, ls);
        }
    }
}
vector<int> dfsRecursive(int V, vector<int> al[]) {
    int vv[V] = {0};
    int start = 0;

    vector<int> ls;

    dfs(start, al, vv, ls);
    return ls;
}

vector<int> dfsIterative(int V, vector<int> al[]) {
    vector<bool> vv(V, false);
    stack<int> s;
    vector<int> dfs;
    vv[0] = true; s.push(0);
    while(!s.empty()){
        int top = s.top(); s.pop();
        dfs.push_back(top);
        for(int i: al[top]){
            if (!vv[i]){
                s.push(i);
                vv[i]=true;
            }
        }
    }
    return dfs;
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
    vector<int> al[5];

    addEdge(al, 0, 2);
    addEdge(al, 2, 4);
    addEdge(al, 0, 1);
    addEdge(al, 0, 3);

    // recursive traverses by left side , iterative by right side
    vector<int> ans = dfsRecursive(5, al);
    printVector(ans);
    vector<int> ans2 = dfsIterative(5, al);
    printVector(ans2);

    return 0;
}
