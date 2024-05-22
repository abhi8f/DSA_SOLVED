class Solution {
	public long interchangeableRectangles(int[][] rectangles) {
        HashMap<Double, Long> hm = new HashMap<>();

        for(int i = 0; i < rectangles.length; i++) {
        	Double ratio = (double) rectangles[i][0] / rectangles[i][1];
        	hm.put(ratio, hm.getOrDefault(ratio, (long) 0) + 1);
        }

        long ans = 0;
        for(Long x: hm.values()) {
        	ans += x*(x-1)/2;
        }
        return ans;

    }
}
