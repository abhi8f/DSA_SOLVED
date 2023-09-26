vector<int> moveZeros(int n, vector<int> nums) {
    int i=0,j=0;
    while(i<n && j<n){
        if (nums[j]!=0) swap(nums[i++],nums[j++]);
        else j++;
    }
    return nums;
}
