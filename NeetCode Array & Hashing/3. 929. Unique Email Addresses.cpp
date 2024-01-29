class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans = 0;
        set<string> st;
        for(string& s: emails) {
            stringstream ss(s);
            string local, domain;
            getline(ss, local, '@');
            getline(ss, domain, '@');

            string localUnique = "";
            for(char& c: local) {
                if (c == '+') break;
                if (c == '.') continue;
                localUnique += c;
            }
            st.emplace(localUnique + "@" + domain);
        }
        return st.size();
    }
};
