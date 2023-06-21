// TC: O(m*n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2) {
    int row = str1.size(), col = str2.size();
    if (row == 0 || col == 0) return 0;
    vector<int> cur(col, 0);
    int ans = 0;
    for(int i=0;i<row;i++)
        for(int j=col-1;j>=0;j--)
            if (str1[i]==str2[j])ans=max(ans, cur[j]=1+(i>0 && j>0?cur[j-1]:0));
            else cur[j] = 0;
    
    return ans;
}

int main() {
    return 0;
}