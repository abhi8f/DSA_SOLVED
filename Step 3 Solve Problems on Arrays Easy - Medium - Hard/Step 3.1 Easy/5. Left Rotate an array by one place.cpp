vector<int> rotateArray(vector<int>& arr, int n) {
    int start=arr[0];
    for(int i=1; i<n; i++) arr[i-1]=arr[i];
    arr[n-1]=start;
    return arr;
}


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k==0) return;
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin(), nums.end());
    }
};