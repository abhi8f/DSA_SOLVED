class Solution {
  public:
    int isStrong(int N) {
        int* fac = new int[10];
        fac[0] = 1;
        int f = 1;
        for(int i = 1; i<=9; i++) {
            f *= i;
            fac[i] = f;
        }

        int sum = 0;
        int n = N;
        while (n) {
            int rem = n % 10;
            sum += fac[rem];
            n /= 10;
        }
        delete[] fac;
        return sum == N;
    }
};
