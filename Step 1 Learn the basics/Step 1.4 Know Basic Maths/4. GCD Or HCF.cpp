int calcGCD(int n, int m){
    if (m==0) return n;
    if (n>m) return calcGCD(m, n%m);
    else return calcGCD(n, m%n);
}