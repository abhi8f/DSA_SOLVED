// TC: O(N + 2E)
// SC: O(N)
#include <bits/stdc++.h>
using namespace std;

void markWithDfs(vector<vector<int>> &roads, vector<bool> &visited, int i){
    int n=roads.size();
    visited[i]=true;
    for(int j=0;j<n;j++)
        if (roads[i][j]==1 && !visited[j]) markWithDfs(roads,visited,j);
}

int findNumOfStates(vector<vector<int>>& roads, int n) {
    vector<bool> visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++)
        if (!visited[i]) ans++, markWithDfs(roads,visited,i);

    return ans;
}

int main(){
    
    return 0;
}