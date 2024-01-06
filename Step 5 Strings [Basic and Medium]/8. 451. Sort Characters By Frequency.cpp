class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, short>> freqChar('z' + 1);
        for(int i = 0; i < ('z' + 1); i++) {
            freqChar[i].second = i;
        }

        for(char& c: s) {
            freqChar[c].first++;
        }

        sort(freqChar.begin(), freqChar.end(), greater<pair<int, short>>());
        string ans = "";
        for(int i = 0; i<62; i++) {
            if (freqChar[i].first == 0) {
                break;
            }
            ans += string(freqChar[i].first, (char)freqChar[i].second);
        }
        return ans;

    }
};
