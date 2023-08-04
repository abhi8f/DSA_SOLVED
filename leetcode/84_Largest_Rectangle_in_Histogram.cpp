// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
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
};

int main() {
    Solution s;
    vector<int> v = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(v);
    return 0;
}