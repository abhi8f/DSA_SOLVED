// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        vector<int> pre(cols+1,0), cur(cols+1,0);
        int ans=0;
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if (matrix[i-1][j-1]==1) cur[j]=1+min({cur[j-1],pre[j-1],pre[j]});
                else cur[j]=0;
                ans+=cur[j];
            }
            swap(pre,cur);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}