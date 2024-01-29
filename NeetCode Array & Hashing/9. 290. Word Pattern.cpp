class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        stringstream ss(s);
        for(char& c: pattern) {
            if (ss.eof()) return false;
            getline(ss, s, ' ');
            auto search1 = mp1.find(c);
            auto search2 = mp2.find(s);

            if ((search1 != mp1.end()) && (search2 != mp2.end())) {
                if ((search1->second != s) || (search2->second != c)) return false;
            } else if ((search1 == mp1.end()) && (search2 == mp2.end())){
                mp1[c] = s;
                mp2[s] = c;
            } else {
                return false;
            }
        }
        if (ss.eof()) return true;
        return false;
    }
};
