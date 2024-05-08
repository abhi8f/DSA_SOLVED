package _YouTube;

import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int countPalindromicSubsequence(String s) {
    	char[] letters = new char[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                'w', 'x', 'y', 'z'};

    	HashSet<Character> left = new HashSet<>();
    	HashMap<Character, Integer> right = new HashMap<>();
    	HashSet<String> ans = new HashSet<>();

    	for(char c: s.toCharArray()) {
    		right.put(c, right.getOrDefault(c, 0));
    	}

    	for(char c: s.toCharArray()) {
    		right.put(c, right.get(c) - 1);
    		if (right.get(c) == 0) {
    			right.remove(c);
    		}

    		for(int i = 0; i < 26; i++) {
    			if (left.contains(letters[i]) && right.containsKey(letters[i])) {
    				ans.add("" + letters[i] + c);
    			}
    		}

    		left.add(c);
    	}

    	return ans.size();
    }
}
