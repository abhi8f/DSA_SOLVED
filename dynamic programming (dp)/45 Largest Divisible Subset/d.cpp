// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

// class Solution {
//    private:
//     void dfsGetAllLDS(vector<vector<pair<int, char>>> &dp, vector<int> &cur, int i, int j, vector<int> &arr) {
//         if (i < 0 || j < 0 || dp[i][j].first == 0) return;
//         if (dp[i][j].first == 1 && dp[i][j].second != 'u') {
//             cur.push_back(arr[i]);
//         } else if (dp[i][j].second == 'u') {
//             dfsGetAllLDS(dp, cur, i - 1, j, arr);
//         } else if (dp[i][j].second == 'j') {
//             cur.push_back(arr[i]);
//             dfsGetAllLDS(dp, cur, i - 1, j, arr);
//         } else {
//             cur.push_back(arr[i]);
//             dfsGetAllLDS(dp, cur, i - 1, i, arr);
//         }
//         return;
//     }

//    public:
//     vector<int> largestDivisibleSubset(vector<int> &nums) {
//         int n = nums.size();
//         vector<vector<pair<int, char>>> dp(n, vector<pair<int, char>>(n + 1, {0, '0'}));
//         pair<int, char> p1 = {1, '0'}, p0 = {0, '0'};
//         for (int j = 0; j < n; j++) dp[0][j] = (nums[0] % nums[j] == 0 || nums[j] % nums[0] == 0) ? p1 : p0;
//         dp[0][n] = p1;

//         for (int i = 1; i < n; i++)
//             for (int j = i + 1; j <= n; j++) {
//                 int u = dp[i - 1][j].first;
//                 int d = 0;

//                 pair<int, char> pu = {u, 'u'}, pd = {d, '0'}, pb = {u, 'b'};

//                 if (j == n) {
//                     d = 1 + dp[i - 1][i].first;
//                     pd.second = 'i';
//                 } else if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
//                     if (dp[i - 1][i].first == dp[i - 1][j].first) {
//                         if (nums[i] > nums[j]) {
//                             d = 1 + dp[i - 1][i].first;
//                             pd.second = 'i';
//                         } else {
//                             d = 1 + dp[i - 1][j].first;
//                             pd.second = 'j';
//                         }
//                     }
//                     else if (dp[i - 1][i].first < dp[i - 1][j].first){
//                         d = 1 + dp[i - 1][i].first;
//                         pd.second = 'i';
//                     }
//                     else {
//                         d = 1 + dp[i - 1][j].first;
//                         pd.second = 'j';
//                     }
//                 }
//                 pd.first = d;
//                 if (d > u)
//                     dp[i][j] = pd;
//                 else if (u > d)
//                     dp[i][j] = pu;
//                 else
//                     dp[i][j] = pb;
//             }
//         vector<int> cur;
//         dfsGetAllLDS(dp, cur, n - 1, n, nums);
//         reverse(cur.begin(), cur.end());
//         return cur;
//     }
// };

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(n,1), hash(n,-1);
        int maxi=0, maxv=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                if ((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) && dp[i]<dp[j]+1){
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
            v.push_back(nums[maxi]);
            maxi=hash[maxi];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

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
int main(){
    
    return 0;
}