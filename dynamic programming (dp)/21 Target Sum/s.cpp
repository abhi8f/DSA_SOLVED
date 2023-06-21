// TC: O(n*target)
// SC: O(target)
#include <bits/stdc++.h>
using namespace std;

int targetSum(int n, int target, vector<int>& arr) {
    int sum=accumulate(arr.begin(), arr.end(), 0);
    if (sum==0 && target==0) return pow(2,n);
    if (sum<abs(target) || (sum-target)%2) return 0;
    target = (sum-abs(target))/2;
    vector<int> cur(target+1, 0);
    int i=0, zc=0;
    while (i<n && arr[i]==0) zc++, i++;
    cur[0] = 1;
    if (arr[i]<=target) cur[arr[i]] = 1;
    i++;
    for (; i<n; i++)
        for (int j=target; j>=0; j--)
            cur[j] = cur[j] + (j>=arr[i]?cur[j-arr[i]]:0);
    
    return cur[target]*pow(2, zc);
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