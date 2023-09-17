class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e=nums[0], c=1, n=nums.size();
        for(int i=1; i<n; i++){
            if (nums[i]==e) c++;
            else c--;
            if (c<0) c=1, e=nums[i];
        }
        return e;
    }
};