// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int V = wordList.size();

        vector<vector<int>> adjList(V);
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

        int b = V - 1, e;
        for (int i = 0; i < V; i++) {
            if (wordList[i] == endWord) e = i;
        }
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
        return 0;
    }
};
class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string w = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (w == endWord) return steps;
            int ws = w.size();
            for (int i = 0; i < ws; i++) {
                char r = w[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    if (auto search = s.find(w); search != s.end()) {
                        s.erase(search);
                        q.push({w, steps + 1});
                    }
                }
                w[i] = r;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << endl
         << s.ladderLength("hit", "hai", wordList) << endl;
    return 0;
}