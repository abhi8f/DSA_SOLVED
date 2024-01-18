class Solution {
private:
    bool isPrime(int n) {
        int sq = ceil(sqrt(n));

        for(int i = 2; i<=sq; i++) {
            if (n%i == 0) return false;
        }
        return true;
    }
public:
    bool isSumOfKprimes(int N, int K)
    {
        if (N < 2*K) return false;

        if (K == 1) {
            if (isPrime(N)) return true;
            return false;
        }
        if (K == 2) {
            if (N%2 == 0) return true;

            return isPrime(N-2);
        }
        return true;
    }
};
