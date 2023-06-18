// TC: O(n*target)
// SC: O(n) + O(n*target) = O(n*target)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int target, vector<int>& arr, vector<vector<int>>& mv){
    if (i<0) return target==0?1:0;
    if (mv[i][target]!=-1) return mv[i][target];
    return mv[i][target] = (r(i-1, target, arr, mv) + (target>=arr[i]?r(i-1, target-arr[i], arr, mv):0));
}

int targetSum(int n, int target, vector<int>& arr) {
    int sum=accumulate(arr.begin(), arr.end(), 0);
    if (sum<abs(target) || (sum-target)%2) return 0;
    target = (sum-abs(target))/2;
    vector<vector<int>> mv(n, vector<int>(target+1, -1));
    return r(n-1, target, arr, mv);
}

int main(){
/*
10 -39
0 13 18 14 15 19 21 2 8 1
*/
    int n=9, target=-39;
    vector<int> arr = {13, 18, 14, 15, 19, 21, 2, 8, 1};
    cout<<targetSum(n, target, arr);
    return 0;
}