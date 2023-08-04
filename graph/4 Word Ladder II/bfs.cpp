// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        int ansLength=-1;
        q.push({beginWord});
        vector<string> clearList;
        int level=1;
        while(!q.empty()){
            vector<string> cV=q.front();
            q.pop();
            int n=cV.size();
            string cS=cV.back();
            if (ansLength!=-1 && ansLength!=n) break;
            if (cS==endWord){
                if (ans.size()==0) {
                    ansLength=n;
                    ans.push_back(cV);
                }
                else if (n==ansLength) ans.push_back(cV);
                else break;
            }
            if (level!=n){
                level++;
                for(string lS: clearList) s.erase(lS);
                clearList.clear();
            }
            int sN=cS.size();
            for(int i=0;i<sN;i++){
                char r=cS[i];
                for(char c='a';c<='z';c++){
                    cS[i]=c;
                    if (s.find(cS)!=s.end()){
                        clearList.push_back(cS);
                        cV.push_back(cS);
                        q.push(cV);
                        cV.pop_back();
                    }
                }
                cS[i]=r;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    s.findLadders("hit", "cog", wordList);
    cout<<"end"<<endl;
    return 0;
}