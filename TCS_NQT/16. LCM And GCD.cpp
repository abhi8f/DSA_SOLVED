class Solution {
    long long gcd(long long A, long long B) {
        if (B == 0) return A;
        return gcd(B, A%B);
    }
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        if (B>A) swap(A, B);
        long long g = gcd(A, B);
        long long l = A*B/g;

        return {l, g};
    }
};
