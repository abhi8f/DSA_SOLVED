class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char& c: tasks) {
            count[c-'A']++;
        }
        priority_queue<int> pq;
        for(int& x: count) {
            if (x > 0) {
                pq.emplace(x);
            }
        }
        queue<pair<int, int>> q;
        int time = 0;
        while (!q.empty() || !pq.empty()) {
            time++;
            if (!pq.empty()) {
                int t = pq.top() - 1;
                pq.pop();
                if (t != 0) {
                    q.push({time + n, t});
                }
            }
            if (!q.empty() && q.front().first == time) {
                pq.emplace(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};
