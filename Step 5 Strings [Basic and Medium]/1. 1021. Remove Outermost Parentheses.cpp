
class Solution {
public:
    string removeOuterParentheses(string &s) {
        stringstream ans;
        int cnt = 0;

        for (char& c : s) {
            if (c == '(' && cnt++ > 0) {
                ans << c;
            } else if (c == ')' && --cnt > 0) {
                ans << c;
            }
        }

        return ans.str();
    }
};
