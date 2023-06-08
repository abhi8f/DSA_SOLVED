// TC: O(2^(n*k))
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

bool r(int i, int k, vector<int> &arr) {
    if (i<0) return k==0?true:false;
    return r(i-1, k-arr[i], arr) || r(i-1, k, arr);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return r(n-1, k, arr);
}

int main(){
    
    return 0;
}