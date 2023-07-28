// TC: O(n*n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        int maxv=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int misMatch=1, p1=words[i].size()-1, p2=words[j].size() -1;
                if (abs(p1-p2)>1) continue;
                while(i>=0 && j>=0 && misMatch>=0){
                    if (words[i][p1]!=words[j][p2]) p1--, misMatch--;
                    else p1--,p2--;
                }
                if (misMatch!=0) continue;
                dp[i]=max(dp[i], dp[j]+1);
            }
            maxv=max(maxv,dp[i]);
        }
        return maxv;
    }
};
bool cmp(const string lhs, const string rhs) {
   return lhs.length() < rhs.length();
}
int longestStrChain(vector<string> &arr){
    sort(arr.begin(), arr.end(), cmp);
    int n=arr.size();
    vector<int> dp(n,1);
    int maxv=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int misMatch=1, p1=arr[i].size()-1, p2=arr[j].size() -1;
            if (abs(p1-p2)!=1) continue;
            while(p1>=0 && p2>=0 && misMatch>=0){
                if (arr[i][p1]!=arr[j][p2]) p1--, misMatch--;
                else p1--,p2--;
            }
            if (misMatch==abs(p1-p2)) {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        maxv=max(maxv,dp[i]);
    }
    return maxv;
}


int main(){
    vector<string> v={"jcuthn", "jcthn", "jrcuthn", "whej"};
    // vector<string> v={"b","a","ba","bca","bda","bdca"};
    // vector<string> v={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout<<endl<<longestStrChain(v);
    return 0;
}