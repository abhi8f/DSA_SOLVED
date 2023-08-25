class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n=intervals.size();
        vector<vector<int>> ans;
        int start=0, cur=0, next=1;

        while(next<n) { 
            if (intervals[cur][1]>=intervals[next][1]) next++;
            else if (intervals[cur][1]>=intervals[next][0]) cur=next++;
            else {
                ans.push_back({intervals[start][0], intervals[cur][1]});
                start=cur=next++;
            }
        }
        ans.push_back({intervals[start][0], intervals[cur][1]});
        return ans;
    }
};