// TC: O(n*n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;



class Solution {
    private:
    void dfs(vector<vector<pair<int,int>>> &dp, vector<int>& cuts, vector<int> &v, int i, int j){
        if (dp[i][j].second==-1) return;
        v.push_back(cuts[dp[i][j].second]);
        dfs(dp,cuts,v,i,dp[i][j].second);
        dfs(dp,cuts,v,dp[i][j].second,j);

    }
   public:
    vector<int> minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int nn=cuts.size();
        vector<vector<pair<int,int>>> dp(nn,vector<pair<int,int>>(nn,{0,-1}));
        for(int i=nn-3;i>=0;i--){
            for(int j=i+2;j<nn;j++){
                int ans=INT_MAX;
                int ai=-1;
                for(int k=i+1;k<j;k++){
                    int cur=cuts[j]-cuts[i] + dp[i][k].first + dp[k][j].first;
                    if (cur<ans){
                        ans=cur;
                        ai=k;
                    }
                }
                dp[i][j]={ans,ai};
            }
        }
        vector<int> v;
        dfs(dp,cuts,v,0,nn-1);
        return v;
    }
};

void dfs(vector<vector<pair<int,int>>> &dp, vector<int>& cuts, vector<int> &v, int i, int j){
    if (dp[i][j].second==-1) return;
    v.push_back(cuts[dp[i][j].second]);
    dfs(dp,cuts,v,i,dp[i][j].second);
    dfs(dp,cuts,v,dp[i][j].second,j);

}

vector<int> rodCut(int n, vector<int> &cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    int nn=cuts.size();
    vector<vector<pair<int,int>>> dp(nn,vector<pair<int,int>>(nn,{0,-1}));
    for(int i=nn-3;i>=0;i--){
        for(int j=i+2;j<nn;j++){
            int ans=INT_MAX;
            int ai=-1;
            for(int k=i+1;k<j;k++){
                int cur=cuts[j]-cuts[i] + dp[i][k].first + dp[k][j].first;
                if (cur<ans){
                    ans=cur;
                    ai=k;
                }
            }
            dp[i][j]={ans,ai};
        }
    }
    vector<int> v;
    queue<pair<int,int>> q;
    q.push({0,nn-1});
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if (dp[i][j].second==-1) continue;
        v.push_back(cuts[dp[i][j].second]);
        q.push({i,dp[i][j].second});
        q.push({dp[i][j].second,j});
    }
    return v;
}

int main() {
    Solution s;
    // vector<int> ac = {1, 3, 4, 5};
    // cout << s.minCost(7, ac) << endl;
    // vector<int> ac={5,6,1,4,2};
    // cout<<s.minCost(9,ac)<<endl;
    // vector<int> ac={1,3};
    // vector<int> wc=s.minCost(5,ac);
    vector<int> ac={1,2,5};
    vector<int> wc=s.minCost(6,ac);
    // vector<int> ac={3};
    // vector<int> wc=s.minCost(5,ac);
    return 0;
}