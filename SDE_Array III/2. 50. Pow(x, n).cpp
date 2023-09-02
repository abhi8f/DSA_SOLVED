class Solution {
public:
    double myPow(double x, int n) {
        if (x==0) return 0;
        if (n==0) return 1;
        double ans=1;
        if (n%2!=0) {
            if (n>0) ans=x, n--;
            else ans=1/x, n++;
        }    
        double subAns=myPow(x, n/2);
        ans*=subAns*subAns;
        return ans;
    }
};