class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        for (int number : nums) {
            hs.add(number);
        }

        int ans = 0;

        for(int x: nums) {
            if (!hs.contains(x - 1)) {
                int count = 1;
                int y = x + 1;
                while (hs.contains(y)) {
                    ++count;
                    ++y;
                }
                ans = Math.max(ans, count);
            }
        }
        return ans;
    }
}
