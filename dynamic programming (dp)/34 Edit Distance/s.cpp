// TC: O(m*n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<int> pre(n + 1, 0), cur(n + 1, 0);
    for (int j = 1; j <= n; j++) pre[j] = j;

    for (int i = 1; i <= m; i++){
        cur[0]=i;
        for (int j = 1; j <= n; j++) 
            if (str1[i - 1] == str2[j - 1])
                cur[j] = pre[j - 1];
            else
                cur[j] = 1 + min({pre[j - 1], pre[j], cur[j - 1]});
        
        swap(pre,cur);
    
    }
    return pre[n];
}

class Solution {
   public:
    int minDistance(string word1, string word2) {
        swap(word1, word2); // i did first in codestudio
        int m = word1.size(), n = word2.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int j = 1; j <= n; j++) pre[j] = j;

        for (int i = 1; i <= m; i++){
            cur[0]=i;
            for (int j = 1; j <= n; j++) 
                if (word1[i - 1] == word2[j - 1])
                    cur[j] = pre[j - 1];
                else
                    cur[j] = 1 + min({pre[j - 1], pre[j], cur[j - 1]});
            
            swap(pre,cur);
        
        }
        return pre[n];
    }
};

int main() {
/*
whgtdwhgtdg
aswcfg
*/
    string str1="whgtdwhgtdg", str2="aswcfg";
    cout<<"hello"<<endl;
    cout << editDistance(str1, str2) << endl;
    cout<<"world"<<endl;
    return 0;
}