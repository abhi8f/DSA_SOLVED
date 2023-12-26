class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string tmp = "";

        for(int i = (s.size() - 1); i>=0; i--) {
            if (s[i] == ' ') {
                if (tmp != "") {
                    reverse(tmp.begin(), tmp.end());
                    ans += tmp + " ";
                    tmp = "";
                }
            } else {
                tmp += s[i];
            }
        }
        if (tmp == "") {
            ans.pop_back();
        } else {
            reverse(tmp.begin(), tmp.end());
            ans += tmp;
        }
        return ans;
    }
};
