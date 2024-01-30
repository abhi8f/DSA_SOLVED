class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        int ans = 0;
        while (ss >> s) {
            ans = s.size();
        }
        return ans;
    }
};
