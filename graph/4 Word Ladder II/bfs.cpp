// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        int ansLength = -1;
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, vector<string>>> q;
        q.push({beginWord, {beginWord}});
        while (!q.empty()) {
            string w = q.front().first;
            vector<string> v = q.front().second;
            q.pop();
            if (ansLength != -1 && v.size() != ansLength) continue;
            if (w == endWord) {
                if (ansLength == -1) {
                    ans.push_back(v);
                    ansLength = v.size();
                    continue;
                }
                ans.push_back(v);
                continue;
            }
            int ws = w.size();
            for (int i = 0; i < ws; i++) {
                char r = w[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    if (auto search = s.find(w); search != s.end()) {
                        if (w != endWord) s.erase(search);
                        v.push_back(w);
                        q.push({w, v});
                        v.pop_back();
                    }
                }
                w[i] = r;
            }
        }

        return ans;
    }
};

class Solution {
   private:
    vector<vector<int>> adjList;
    vector<vector<string>> ans;
    int V, b, e, ansLength = -1;

    int bfs() {
        queue<pair<int, int>> q;
        vector<int> visited(V, false);
        q.push({b, 1});
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            visited[p.first] = true;
            for (int i : adjList[p.first]) {
                if (e == i) return p.second + 1;
                if (visited[i]) continue;
                q.push({i, p.second + 1});
            }
        }
        return -1;
    }
    void dfs(int i, vector<int> visited, vector<string> seq, vector<string>& wordList) {
        if (seq.size() >= ansLength) return;
        seq.push_back(wordList[i]);
        if (i == e) {
            ans.push_back(seq);
            return;
        }
        visited[i] = true;
        for (int j: adjList[i]){
            if (visited[i]) continue;
            dfs(j,visited,seq,wordList);
        }
    }

   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        V = wordList.size();

        adjList.resize(V);
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int count = 2;
                int k = wordList[i].size() - 1;

                while (k != -1 && count != 0) {
                    if (wordList[i][k] != wordList[j][k]) count--;
                    k--;
                }

                if (count == 1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        b = V - 1;
        for (int i = 0; i < V; i++) {
            if (wordList[i] == endWord) e = i;
        }

        ansLength = bfs();
        if (ansLength == -1) return ans;
        vector<int> visited(V, false);
        dfs(b,visited,{},wordList);
    }
    return ans;
};

int main() {
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit", "cog", wordList);
    return 0;
}