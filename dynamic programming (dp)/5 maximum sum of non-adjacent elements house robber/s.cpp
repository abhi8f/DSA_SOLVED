// TC: O(n)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum1(vector<int> &nums) {
    int n=nums.size();
    int preNo = 0, preYes = nums[0];
    for(int i=1;i<n;i++){
        int newPreNo=preYes;
        int newPreYes=max(preNo+nums[i], preYes);
        preNo=newPreNo;
        preYes=newPreYes;
    }
    return max(preNo,preYes);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n=nums.size();
    int pre2=0, pre=nums[0];
    for(int i=1;i<n;i++){
        int newPre=max(nums[i]+pre2,pre);
        pre2=pre;
        pre=newPre;
    }
    return pre;
}

int main() {
    // 1 2 3 1 3 5 8 1 9
    vector<int> v = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    cout << maximumNonAdjacentSum(v) << endl;
    return 0;
}