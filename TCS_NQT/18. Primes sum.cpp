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
    string isSumOfTwo(int N){
        if (N < 4) return "No";
        if (N%2==0) return "Yes";
        if (isPrime(N-2)) return "Yes";
        return "No";
    }
};
