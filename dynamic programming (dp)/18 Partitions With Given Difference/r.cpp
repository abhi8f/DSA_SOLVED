// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, double k, vector<int> &arr){
    if (i<0) return k==0?1:0;
    return r(i-1, k-arr[i], arr) + r(i-1, k, arr);
}

int countPartitions(int n, int d, vector<int> &arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0);
    double k = (sum-d)/2;
    if ((sum-d)<0 || (sum-d)%2) return 0;
    return r(n-1, k, arr);
}


int main(){
    int n=4, d=10;
    vector<int> arr = {0, 0, 3, 6};
    return 0;
}