
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int& n: nums) {
            temp.push_back(to_string(n));
        }
        sort(temp.begin(), temp.end(), [](string& a, string& b)->bool {
            return a+b>b+a;
        });
        string ans = "";
        for(string& s: temp) {
            ans += s;
        }
        return ans[0] == '0' ? "0" : ans;
    }
};
