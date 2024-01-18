class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if (str1.size() != str2.size()) return 0;
        vector<int> count(26, 0);
        for(char& c: str1) {
            count[c-'a']++;
        }
        for(char& c: str2) {
            count[c-'a']--;
        }
        int ans = 0;
        for(int& x: count) {
            if (x > 0)
                ans += x;
        }
        return ans <= k;
    }
};
