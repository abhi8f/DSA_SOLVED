class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if(strs.size() == 0) return s;
        int minLen = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            minLen = min(minLen, (int)strs[i].size());
        }
        for(int i=0;i<minLen;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != strs[j-1][i]) return s;
            }
            s += strs[0][i];
        }
        return s;
    }
};
