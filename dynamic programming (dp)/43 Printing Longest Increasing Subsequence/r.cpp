// TC: O(2^n)
// SC: O(n*ans)
#include <bits/stdc++.h>
using namespace std;

vector<int> r(int i, int pre, vector<int> &arr){
    if (i==arr.size()) return {};
    vector<int> v1 = r(i+1,pre,arr);
    vector<int> v2;
    if (pre==-1 || arr[i]>arr[pre]) {
        v2={arr[i]};
        vector<int> v3=r(i+1,i,arr);
        v2.insert(v2.end(), v3.begin(), v3.end());
    }
    if (v1.size()>v2.size()) return v1;
    else return v2;
}

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	return r(0,-1,arr);
}

int main(){
    
    return 0;
}
