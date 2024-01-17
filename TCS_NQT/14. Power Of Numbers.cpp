#define mv 1000000007;

class Solution{
    public:
    //You need to complete this fucntion

    long long power(int N,int R)
    {
       if (N==0) return 0;
       if (R==0) return 1;

       long long ans = 1;
       long long n = N;

       while (R) {
           if (R%2==0) {
              n*=n;
              n = n%mv;
              R/=2;
           } else {
              ans *= n;
              ans = ans%mv;
              R--;
           }
       }
       return ans;

    }

};
