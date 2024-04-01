class Solution {
    public void sortColors(int[] nums) {
        int l = nums.length;
        int zeroWall = 0;
        int twoWall = l - 1;

        int i = zeroWall;

        while (i <= twoWall) {
            switch(nums[i]) {
                case 0:
                    swapElements(nums, zeroWall, i);
                    zeroWall++;
                    i++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    swapElements(nums, twoWall, i);
                    twoWall--;
                    break;
            }
        }
    }
    public static void swapElements(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}
