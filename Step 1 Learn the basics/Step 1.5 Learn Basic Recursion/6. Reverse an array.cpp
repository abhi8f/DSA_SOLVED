vector<int> reverseArray(int n, vector<int> &nums){
    for(int i=0; i<n/2; i++){
        swap(nums[i], nums[n-i-1]);
    }
    return nums;
}

void rec(int i, vector<int> &nums, vector<int> &revNums){
    if (i<0) return;
    revNums.push_back(nums[i]);
    rec(i-1, nums, revNums);
}

vector<int> reverseArray(int n, vector<int> &nums){
    vector<int> revNums;
    rec(n-1, nums, revNums);
    return revNums;
}

void rec(int i, vector<int> &nums){
    if (i<0) return;
    swap(nums[i], nums[nums.size()-1-i]);
    rec(i-1, nums);
}

vector<int> reverseArray(int n, vector<int> &nums){
    rec(n/2-1, nums);
    return nums;
}
