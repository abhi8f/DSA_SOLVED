class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);
        int mid, load, curDays;
        while (low <= high) {
            mid = low + (high - low)/2;
            load = mid, curDays=0;
            for(int x: weights){
                if (x<=load) load -= x;
                else curDays++, load = mid - x;
            }
            curDays++;
            if (curDays<=days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};