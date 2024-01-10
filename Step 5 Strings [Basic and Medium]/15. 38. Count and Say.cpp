class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string pre = countAndSay(n - 1);

        int s = pre.size();
        int i = 0;
        string ans = "";
        while (i < s) {
            int j = i;
            int count = 0;
            while ((j < s) && (pre[j] == pre[i])) {
                count++;
                j++;
            }
            ans += to_string(count);
            ans += pre[i];
            i = j;
        }
        return ans;
    }
};
