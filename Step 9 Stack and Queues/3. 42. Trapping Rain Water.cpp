class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int leftPointer = 0;
        int rightMax = 0;
        int rightPointer = n - 1;
        int ans = 0;

        while (leftPointer <= rightPointer) {
            if (height[leftPointer] <= height[rightPointer]) {
                if (height[leftPointer] >= leftMax) {
                    leftMax = height[leftPointer];
                } else {
                    ans += leftMax - height[leftPointer];
                }
                leftPointer++;
            } else {
                if (height[rightPointer] >= rightMax) {
                    rightMax = height[rightPointer];
                } else {
                    ans += rightMax - height[rightPointer];
                }
                rightPointer--;
            }
        }

        return ans;
    }
};
