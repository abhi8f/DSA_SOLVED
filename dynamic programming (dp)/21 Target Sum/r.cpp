// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int target, vector<int>& arr){
    if (i<0) return target==0?1:0;
    return r(i-1, target, arr) + r(i-1, target-arr[i], arr);
}

int targetSum(int n, int target, vector<int>& arr) {
    int sum=accumulate(arr.begin(), arr.end(), 0);
    if (sum<abs(target) || (sum-target)%2) return 0;
    target = (sum-abs(target))/2;
    return r(n-1, target, arr);
}

int main(){
    
    return 0;
}