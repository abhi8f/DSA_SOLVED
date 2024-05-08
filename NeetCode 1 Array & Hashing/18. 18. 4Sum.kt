class Solution {
    fun fourSum(nums: IntArray, target: Int): List<List<Int>> {
        nums.sort()
        val ans = mutableListOf<List<Int>>()
        val s: Int = nums.size

        for (i in 0 until (s-3)) {
            if (i != 0 && nums[i] == nums[i-1]) continue
            for (j in (i+1) until (s - 2)) {
                if (j != (i+1) && nums[j] == nums[j-1]) continue
                var k: Int = j + 1
                var l: Int = s - 1

                while (k < l) {
                    val sum: Long = nums[i].toLong() + nums[j].toLong() + nums[k].toLong() + nums[l].toLong()
                    if (sum > target.toULong()) l--
                    else if (sum < target.toULong()) k++
                    else {
                        ans.add(listOf(nums[i], nums[j], nums[k++], nums[l--]))
                        while ((k < l) && (nums[k] == nums[k-1])) k++
                        while ((l > k) && (nums[l] == nums[l+1])) l--
                    }
                }
            }
        }
        return ans
    }
}
