class Solution{
public:
    long long int largestPrimeFactor(int N){
        int ans = 0;
        int sq = ceil(sqrt(N));

        if (N % 2 == 0) ans = 2;
        while(N%2==0) N/=2;

        for(int i = 3; i <= sq; i+=2) {
            if (N%i == 0) ans = i;
            while(N%i == 0) N/=i;
        }
        ans = max(ans, N);
        return ans;
    }

};
