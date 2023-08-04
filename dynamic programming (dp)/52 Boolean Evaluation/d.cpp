// TC: O(n*n*n)
// SC: O(n*n*2)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;


int evaluateExp(string &exp) {
    int n=exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));

    for(int i=0; i<=n-1; i+=2) dp[i][i][0]=exp[i]=='F', dp[i][i][1]=exp[i]=='T';

    for(int l=n-3;l>=0;l--){
        for(int r=l+2;r<n;r++){
            long long lt,lf,rt,rf,curT, curF;
            for(int p=l+1;p<=r-1;p+=2){
                lt = dp[l][p - 1][1];
                lf = dp[l][p - 1][0];
                rt = dp[p + 1][r][1];
                rf = dp[p + 1][r][0];
                curT = curF = 0;
                if (exp[p] == '&')
                    curT = lt * rt, curF=lf * rf + lt * rf + lf * rt;
                else if (exp[p] == '|')
                    curT = lt * rt + lt * rf + lf * rt, curF = lf * rf;
                else if (exp[p] == '^')
                    curT = lt * rf + lf * rt, curF = lt * rt + lf * rf;
                dp[l][r][1]= (int)(dp[l][r][1] + curT%1000000007)%1000000007;
                dp[l][r][0]= (int)(dp[l][r][0] + curF%1000000007)%1000000007;
            }
        }
    }
    return dp[0][n-1][1];  
}

int main() {
    string s = "T^T|F|T";
    cout << evaluateExp(s) << endl;
    return 0;
}