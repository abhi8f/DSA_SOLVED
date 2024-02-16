class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        if (N == 0) return 0;
        if (N == 1) {
            printf("move disk %d from rod %d to rod %d\n", 1, from, to);
            return 1;
        }

        long long steps = 1;
        steps += toh(N - 1, from, aux, to);
        printf("move disk %d from rod %d to rod %d\n", N, from, to);
        steps += toh(N - 1, aux, to, from);

        return steps;
    }

};
