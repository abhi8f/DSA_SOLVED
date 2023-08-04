// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, int *arr){
    if (j-i==1) return 0;
    if (i+2==j) return arr[i]*arr[i+1]*arr[i+2];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
        ans=min(
            ans,
            arr[i]*arr[k]*arr[j]+r(i,k,arr)+r(k,j,arr)
        );
    return ans;
}

int matrixChainMultiplication(int* arr, int n) {
    if (n==1) return 0;
    return r(0,n,arr);
}

int main(){
    
    return 0;
}