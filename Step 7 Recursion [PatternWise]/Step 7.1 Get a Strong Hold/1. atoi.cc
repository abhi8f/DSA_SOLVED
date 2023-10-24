class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while(i<n && s[i]==' ') i++;

        if (i == n) return 0;
        bool pos = true;
        if (s[i] == '-') {
            if ((i+1)==n || isdigit(s[i+1])==0) return 0;
            pos = false, i++;
        }
        if (s[i] == '+') {
            if ((i+1)==n || isdigit(s[i+1])==0) return 0;
            i++;
        }

        int ans = 0, val;
        while(i<n && isdigit(s[i])) {
            val = (int)(s[i] - '0');
            if ((ans > 214748364) || (ans == 214748364 && val > 7)) return INT_MAX;
            if ((ans < -214748364) || (ans == -214748364 && val > 8)) return INT_MIN;
            ans *= 10;
            ans += pos ? val : -val;
            i++;
        }
        return ans;
    }
};


