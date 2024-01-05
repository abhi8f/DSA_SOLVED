class Solution {
private:
    void getLPS(string &needle, vector<int> &lps) {
        int n = needle.size();
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < n) {
            if (needle[len] == needle[i]) {
                lps[i] = len = len + 1;
                i++;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m);
        getLPS(needle, lps);

        int i = 0;
        int j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
            if (j == m) {
                return i - j;
            }
        }
        return -1;
    }
};
