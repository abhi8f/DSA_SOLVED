// TC: O(n*n)
// SC: O(n*n*ans)
#include <bits/stdc++.h>
using namespace std;

vector<int> r(int i, int pre, vector<int> &arr, vector<vector<vector<int>>> &mv){
    if (i==arr.size()) return {};
    if (mv[i][pre+1].size()!=0) return mv[i][pre+1];
    vector<int> v1 = r(i+1,pre,arr, mv);
    vector<int> v2;
    if (pre==-1 || arr[i]>arr[pre]) {
        v2={arr[i]};
        vector<int> v3=r(i+1,i,arr, mv);
        v2.insert(v2.end(), v3.begin(), v3.end());
    }
    if (v1.size()>v2.size()) return v1;
    else return v2;

    return mv[i][pre+1] = v1.size()>v2.size()?v1:v2;
}

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    vector<vector<vector<int>>> mv(n, vector<vector<int>>(n+1));
	return r(0,-1,arr,mv);
}

// time limit exceeded;

int main(){
    
    return 0;
}
