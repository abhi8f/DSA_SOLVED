// TC: O(n*n*2)
// SC: O(n) + O(n*n*2)
#include <bits/stdc++.h>
using namespace std;


int r(vector<int> &arr, int i, int pre, bool asc, vector<vector<vector<int>>> &mv){
    if (i<0) return 0;
    if (mv[i][pre][asc]!=-1) return mv[i][pre][asc];
    if (asc==true){
        int t1=r(arr,i-1,pre, true,mv), t2=r(arr,i,pre, false,mv), t3=0;
        if (pre==arr.size() || arr[i]>arr[pre]) t3=1+r(arr,i-1,i,true, mv);
        return mv[i][pre][asc] = max(t1,max(t2,t3));
    } else {
        int t1=r(arr,i-1,pre, false,mv), t3=0;
        if (pre==arr.size() || arr[i]<arr[pre]) t3 = 1+r(arr, i-1,i, false, mv);
        return mv[i][pre][asc] = max(t1,t3);
    }
}

int longestBitonicSubsequence(vector<int>& arr, int n) {
    vector<vector<vector<int>>> mv(n, vector<vector<int>>(n+1, vector<int>(2,-1)));
    return r(arr, n-1,n, true, mv);
}

int main() {
    vector<int> v={2, 44, 38, 15, 21};
    cout<<endl<<endl<<longestBitonicSubsequence(v,5)<<endl;
    return 0;
}