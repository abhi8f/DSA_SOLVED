// TC: O(n*n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, int *arr, vector<vector<int>> &mv){
    if (j-i==1) return 0;
    if (i+2==j) return arr[i]*arr[i+1]*arr[i+2];
    if (mv[i][j]!=-1) return mv[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
        ans=min(
            ans,
            arr[i]*arr[k]*arr[j]+r(i,k,arr,mv)+r(k,j,arr,mv)
        );
    return mv[i][j] = ans;
}

int matrixChainMultiplication(int* arr, int n) {
    if (n==1) return 0;
    vector<vector<int>> mv(n+1,vector<int>(n+1,-1));
    return r(0,n,arr,mv);
}

int main(){
    
    return 0;
}