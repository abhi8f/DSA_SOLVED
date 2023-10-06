int inversionsByMergeSort(int l, int r, vector<int>&a){
    if (l>=r) return 0;
    int m=l+(r-l)/2;
    int ans=inversionsByMergeSort(l, m, a) + inversionsByMergeSort(m+1, r, a);
    
    int p=m, q=r, k=r-l;
    vector<int> tmp(r-l+1);
    while(p>=l && q>m){
        if (a[p]>a[q]) tmp[k--]=a[p--], ans+=q-m;
        else tmp[k--]=a[q--];
    }
    while(p>=l) tmp[k--]=a[p--];
    while(q>m) tmp[k--]=a[q--];
    
    for(int i=l; i<=r; i++) a[i]=tmp[i-l];
    return ans;
}