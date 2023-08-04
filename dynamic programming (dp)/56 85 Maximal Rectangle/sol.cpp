// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int ans=0;
    s.push(-1);
    int cur;
    for(int i=0;i<n;i++){
        while(s.top()!=-1 && heights[s.top()]>=heights[i]){
            cur=s.top();
            s.pop();
            ans=max(ans,heights[cur]*(i-s.top()-1));
        }
        s.push(i);
    }
    while(s.top()!=-1){
        cur=s.top();
        s.pop();
        ans=max(ans,heights[cur]*(n-s.top()-1));
    }
    return ans;
}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        vector<int> heights(col,0);
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if (matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int cur=largestRectangleArea(heights);
            ans=max(ans, cur);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}