// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int n=arr.size();
	vector<int> dp(n,1), hash(n,-1);
    int maxi=0, maxv=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            if (arr[i] % arr[j] == 0 && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        if (dp[i]>maxv){
            maxv=dp[i];
            maxi=i;
        }
    }
    vector<int> v;
    while(maxi!=-1){
        v.push_back(arr[maxi]);
        maxi=hash[maxi];
    }
    reverse(v.begin(),v.end());
    return v;
}

int main() {
    // vector<int> v = {4, 8, 10, 240};
    // Solution s;
    // v = s.largestDivisibleSubset(v);
    vector<int> v = {10, 2, 5, 5, 10, 17};
    v=divisibleSet(v);
    cout << endl;
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}