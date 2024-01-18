class Solution{
public:
    int decimalEquivalent(string N, int b){
        int ans = 0;
        int mul = 1;
        for(int i = N.size()-1; i>=0; i--) {
            int val;
            if ((int)N[i] >= (int)'A') {
                val = (int)N[i] - (int)'A' + 10;
            } else {
                val = (int)N[i] - (int)'0';
            }
            if (val >= b) {
                return -1;
            }
            ans += mul * val;
            mul *= b;
        }
        return ans;
    }
};
