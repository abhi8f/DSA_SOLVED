// TC: O(m*n) + O(m+n) = O(m*n)
// SC: O(m*n*)
#include <bits/stdc++.h>
using namespace std;

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int row = a.size(), col = b.size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for(int j=0; j<col; j++) dp[0][j] = a[0]==b[j]?1:0;
    for(int i=1;i<row;i++)
        for(int j=0;j<col;j++)
            dp[i][j]=a[i]==b[j]?1+dp[i-1][j-1]:max(dp[i-1][j], dp[i][j-1]);
    
    vector<int> ans;
    int i=row-1, j=col-1;
    while(i>=0 && j>=0){
        if (a[i]==b[j]){
            ans.push_back(a[i]);
            i--; j--;
        }else if (i>0 && dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    
    return 0;
}