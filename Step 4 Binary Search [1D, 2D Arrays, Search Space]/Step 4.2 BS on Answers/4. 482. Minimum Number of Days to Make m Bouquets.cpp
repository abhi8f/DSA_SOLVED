class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if (n<(double)m*k) return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());

        int mid, cK, cM;
        while (low <= high){
            mid = low + (high - low)/2, cK=cM=0;
            for(int x: bloomDay){
                if (x<=mid) cK++;
                else cK=0;
                if (cK==k) cK=0, cM++;
            }
            if (cM>=m) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }
};