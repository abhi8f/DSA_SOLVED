class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<Integer, ArrayList<String>> m = new HashMap<>();

        for(String x: strs) {
            ArrayList<Integer> al = new ArrayList<>(Collections.nCopies(26, 0));
            char[] ca = x.toCharArray();
            for(char c: ca) {
                al.set(c - 'a', 1 + al.get(c - 'a'));
            }
            int key = al.hashCode();
            m.computeIfAbsent(key, k -> new ArrayList<String>()).add(x);

        }
        List<List<String>> ans = new ArrayList<>();
        ans.addAll(m.values());

        return ans;
    }
}
