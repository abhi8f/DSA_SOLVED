bool isValid(string& s, int l, int r, bool& del) {
    if (l >= r) return true;
    while (l < r) {
        if (del && (s[l] != s[r])) return false;
        if (s[l] != s[r]) {
            del = true;
            return isValid(s, l+1, r, del) || isValid(s, l, r-1, del);
        } else {
            l++;
            r--;
        }
    }
    return true;


}

class Solution {
public:
    bool validPalindrome(string s) {
        bool del = false;
        return isValid(s, 0, s.size() - 1, del);
    }
};
