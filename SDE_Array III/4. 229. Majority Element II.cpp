class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1=INT_MIN, e2=INT_MIN, c1=0, c2=0, moreThan=floor(nums.size()/3);
        for(int x: nums){
            if (c1==0 && x!=e2) e1=x, c1=1;
            else if (c2==0 && x!=e1) e2=x, c2=1;
            else if (x==e1) c1++;
            else if (x==e2) c2++;
            else c1--, c2--;
        }
        c1=0, c2=0;
        for(int x: nums)
            if (x==e1) c1++;
            else if (x==e2) c2++;
        
        vector<int> ans;
        if (c1>moreThan) ans.push_back(e1);
        if (c2>moreThan) ans.push_back(e2);
        return ans;
    }
};