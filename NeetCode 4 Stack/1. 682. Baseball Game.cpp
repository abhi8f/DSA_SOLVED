class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        for(string& s: operations) {
            if (s == "+") {
                int pre = stk.top();
                stk.pop();
                int sum = pre + stk.top();
                stk.push(pre);
                stk.push(sum);
            } else if (s == "D") {
                stk.push(stk.top()*2);
            } else if (s == "C") {
                stk.pop();
            } else {
                stk.push(stoi(s));
            }
        }
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
