class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int pos = true;

        int i = 0;
        int n = s.size();

        while ((i < n) && (s[i] == ' ')) {
            i++;
        }
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            pos = false;
            i++;
        }
        while ((i<n) && isdigit(s[i])) {
            if (ans < -214748364) {
                if (pos) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            } else if (ans == -214748364) {
                if (pos && (((int)s[i] - (int)'0') > 7)) {
                    return INT_MAX;
                } else if (((int)s[i] - (int)'0') > 8){
                    return INT_MIN;
                }
            }
            ans *= 10;
            ans -= (int)s[i] - (int)'0';
            i++;
        }
        if (pos) {
            ans = -ans;
        }
        return ans;
    }
};
