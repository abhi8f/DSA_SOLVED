class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a == b) {
            return 1;
        }
        int n1 = a.size();
        int n2 = b.size();

        int times = ceil(float(n2) / float(n1));
        string repeat = "";
        for(int i = 0; i < times; i++) {
            repeat += a;
        }
        if (repeat.find(b) != string::npos) {
            return times;
        }
        repeat += a;
        if (repeat.find(b) != string::npos) {
            return times + 1;
        }

        return -1;
    }
};
