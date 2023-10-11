int floorSqrt(int x) {
    long long l=0, r=ceil((double)x/2), m, ms;
    while(l<=r){
        m=l+(r-l)/2;
        ms=m*m;
        if (ms<=x) l=m+1;
        else r=m-1;
    }
    return r;
}
