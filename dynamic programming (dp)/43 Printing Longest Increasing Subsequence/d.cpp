// TC: O(n*n)
// SC: O(n*n*2) for first, O(n) for second
#include <bits/stdc++.h>
using namespace std;

// for all
// void dfsGetAllLIS1(vector<vector<int>> &ans, vector<vector<pair<int,char>>> &dp, vector<int> &cur, int i, int j,vector<int> &arr) {
//     if (i<0 || j<0 || dp[i][j].first==0) return;
//     if (dp[i][j].first==1 && dp[i][j].second!='u'){
//         cur.push_back(arr[i]);
//         ans.push_back(cur);
//         cur.pop_back();
//     }
//     else if (dp[i][j].second=='u') dfsGetAllLIS(ans,dp,cur,i-1,j,arr);
//     else if (dp[i][j].second=='d') {
//         cur.push_back(arr[i]);
//         dfsGetAllLIS(ans,dp,cur,i-1,i,arr);
//         cur.pop_back();
//     }
//     else {
//         dfsGetAllLIS(ans,dp,cur,i-1,j,arr);
//         cur.push_back(arr[i]);
//         dfsGetAllLIS(ans,dp,cur,i-1,i,arr);
//         cur.pop_back();
//     }
//     return ;
// }

// vector<int> printingLongestIncreasingSubsequence1(vector<int> arr, int n) {
//     vector<vector<pair<int,char>>> dp(n, vector<pair<int,char>>(n + 1, {0,'0'}));
//     pair<int,char> p1={1,'0'}, p0={0,'0'};
//     for (int j = 0; j < n; j++) dp[0][j] = arr[0] < arr[j] ? p1 : p0;
//     dp[0][n] = {1,'0'};
//     for (int i = 1; i < n; i++)
//         for (int j = i + 1; j <= n; j++){
//             int u = dp[i - 1][j].first;
//             int d = (j == arr.size() || arr[i] < arr[j]) ? 1 + dp[i - 1][i].first : 0;

//             if (u>d) dp[i][j]={u,'u'};
//             else if (d>u) dp[i][j]={d,'d'};
//             else dp[i][j]={d,'b'};
//         }
//     vector<vector<int>> ans;
//     vector<int> cur;
//     dfsGetAllLIS(ans,dp,cur,n-1,n,arr);
//     for(int i=0;i<ans.size();i++){
//         reverse(ans[i].begin(), ans[i].end());
//     }
//     return ans[0];
// }

void dfsGetAllLIS(vector<vector<pair<int,char>>> &dp, vector<int> &cur, int i, int j,vector<int> &arr) {
    if (i<0 || j<0 || dp[i][j].first==0) return;
    if (dp[i][j].first==1 && dp[i][j].second!='u'){
        cur.push_back(arr[i]);
    }
    else if (dp[i][j].second=='u') {
        dfsGetAllLIS(dp,cur,i-1,j,arr);
    }
    else {
        cur.push_back(arr[i]);
        dfsGetAllLIS(dp,cur,i-1,i,arr);
    }
    return ;
}

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    vector<vector<pair<int,char>>> dp(n, vector<pair<int,char>>(n + 1, {0,'0'}));
    pair<int,char> p1={1,'0'}, p0={0,'0'};
    for (int j = 0; j < n; j++) dp[0][j] = arr[0] < arr[j] ? p1 : p0;
    dp[0][n] = {1,'0'};
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++){
            int u = dp[i - 1][j].first;  
            int d =0; 
            
            if (j==n || arr[i]<arr[j]){
                    d=1+dp[i-1][i].first;
            }
            pair<int,char> pu={u,'u'}, pd={d,'d'}, pb={d,'b'};
            if (d>u) dp[i][j]=pd;
            else if (u>d) dp[i][j]=pu;
            else dp[i][j]=pb;
        }
    vector<int> cur;
    dfsGetAllLIS(dp,cur,n-1,n,arr);
    reverse(cur.begin(), cur.end());
    return cur;
}


vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n,1), hash(n,0);
    hash[0]=-1;
    int maxi=0, maxv=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            if (dp[i]<dp[j]+1){
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
    vector<int> v = {5, 38, 36};
    v = printingLongestIncreasingSubsequence(v, 3);
    cout<<endl;
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}