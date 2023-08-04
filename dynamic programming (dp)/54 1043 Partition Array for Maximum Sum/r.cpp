// TC: O(2^n>>)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int l, vector<int> &arr, int k){
    int n=arr.size();
    if (l==n) return 0;
    int mv=arr[l];
    int ans=mv + r(l+1,arr,k);
    for(int p=l+1;p<n && (p-l+1)<=k;p++){
        mv=max(mv,arr[p]);
        ans=max(ans, mv*(p-l+1) + r(p+1,arr,k));
    }
    return ans;
}

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       return r(0,arr,k); 
    }
};

int main(){
    Solution s;
    vector<int> arr={1,2};
    cout<<endl<<s.maxSumAfterPartitioning(arr,2)<<endl;
    return 0;
}