class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int l = (s.size() / 2); l >= 1; l--) {
            string ss = s.substr(0, l);
            if ((n % l) == 0) {
                int times = n/l;
                string repeat = "";
                while(times--) {
                    repeat += ss;
                }
                if (repeat == s) {
                    return true;
                }
            }
        }
        return false;
    }
};
