class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans = {1};
        for(int i = 2; i<=N; i++) {
            int carry = 0;
            int l = ans.size();

            for(int j = 0; j<l; j++) {
                int num = (ans[j] * i) + carry;
                int digit = num % 10;
                carry = num/10;
                ans[j] = digit;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
