class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)?
        str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};

///////// my solution
class Solution {
    bool valid(string& s, string& p) {
        int sl = s.size();
        int pl = p.size();
        if (sl%pl != 0) return false;

        int i = 0;
        while (i < sl) {
            int j = 0;
            while (j < pl) {
                if (s[i] != p[j]) return false;
                i++;
                j++;
            }
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        string ans = "";
        string cur = "";
        int i = 0;

        while ((i < n1) && (i < n2)) {
            if (str1[i] != str2[i]) break;
            cur += str1[i];
            if ((n1 % (i + 1) == 0) && (n2 % (i + 1) == 0)) {
                ans = cur;
            }
            i++;
        }

        if (ans == "") return ans;

        if (!valid(str1, ans) || !valid(str2, ans)) return "";

        return ans;
    }
};
