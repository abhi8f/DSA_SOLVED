class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1, mid, miss;
        while (low <= high) {
            mid = low + (high - low)/2;
            miss = arr[mid] - mid - 1;
            
            if (miss>=k) high = mid - 1;
            else low = mid + 1;
        }
        
        // return l==0? k : arr[l-1] + k - (arr[l-1] - (l-1) - 1);
        return k + low;
    }
};