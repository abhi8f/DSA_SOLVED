class Solution {
private: 
    bool isPalindrome(int i, int j, string &s) {
        while (i<=j && s[i]==s[j]) i++, j--;
        if (i<=j) return false;
        return true;
    }
    void recPart(int i, string &s, int n, vector<string> &cur, vector<vector<string>> &ans) {
        if (i==n) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(s.substr(i, 1));
        recPart(i+1, s, n, cur, ans);
        cur.pop_back();
        for(int j=i+1; j<n; j++) {
            if (!isPalindrome(i, j, s)) continue;
            cur.push_back(s.substr(i, j-i+1));
            recPart(j+1, s, n, cur, ans);
            cur.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;

        int n = s.size();
        recPart(0, s, n, cur, ans);
        return ans;

    }
};
