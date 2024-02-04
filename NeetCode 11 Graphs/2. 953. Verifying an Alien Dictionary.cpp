class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for(int i = 0; i < 26; i++) {
            int c = order[i] - 'a';
            rank[c] = i;
        }
        int n = words.size();
        for(int i = 1; i < n; i++) {
            int n1 = words[i - 1].size();
            int n2 = words[i].size();
            int i1 = 0;
            int i2 = 0;
            while ((i1 < n1) && (i2 < n2)) {
                if (rank[words[i-1][i1] - 'a'] > rank[words[i][i2] - 'a']) return false;
                if (rank[words[i-1][i1] - 'a'] < rank[words[i][i2] - 'a']) break;
                i1++;
                i2++;
            }
            if ((i2 == n2) && (n1 > n2)) return false;
        }
        return true;
    }
};
