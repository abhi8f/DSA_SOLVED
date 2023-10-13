class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, h=*max_element(nums.begin(), nums.end()), m;
        long long cT;
        while (l<=h) {
            m = l + (h-l)/2;
            cT=0;
            for(int x: nums){
                cT+=ceil((double)x/m);
            }
            if (cT<=threshold) h = m - 1;
            else l = m + 1;
        }
        return l;
    }
};