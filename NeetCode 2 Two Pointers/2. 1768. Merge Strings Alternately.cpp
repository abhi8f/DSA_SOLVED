
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        cout<<word1<<endl;
        cout<<word2<<endl;
        int n1 = word1.size();
        int n2 = word2.size();
        int limit = min(n1, n2);
        int i = 0;
        string ans = "";
        while(i < limit) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }
        if (i < n1) {
            ans += word1.substr(i);
        } else if (i < n2) {
            ans += word2.substr(i);
        }
        return ans;
    }
};
