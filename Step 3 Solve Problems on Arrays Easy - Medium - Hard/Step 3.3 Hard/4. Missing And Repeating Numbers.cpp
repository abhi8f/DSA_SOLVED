vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long  n=a.size();
    long long SN=(n*(n+1))/2, S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0, S2=0;
    for(int x: a) S+=x, S2+=(long long)x*x;
    long long add=SN-S, sub=(S2N-S2)/(SN-S);
    int x=(add+sub)/2, y=(sub-add)/2;
    return {y, x};

}