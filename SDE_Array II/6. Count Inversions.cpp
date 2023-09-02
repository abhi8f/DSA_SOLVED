#include <bits/stdc++.h>

#define d(x) cout<<#x<<": "<<x<<endl;

long long getInversionsByMergeSort(long long *arr, int l, int r){
    if (l>=r) return 0;
    int mid=l+(r-l)/2;
    int ans=getInversionsByMergeSort(arr, l, mid)+getInversionsByMergeSort(arr,mid+1,r);
    
    vector<long long> temp(r-l+1);
    int t=r-l, p=mid, q=r;
    while(p>=l && q>mid){
        if (arr[p]>arr[q]) temp[t--]=arr[p--], ans+=q-mid;
        else temp[t--]=arr[q--];
    }
    while(p>=l) temp[t--]=arr[p--];
    while(q>mid) temp[t--]=arr[q--];

    for(t=l;t<=r;t++) arr[t]=temp[t-l];

    return ans;
}

long long getInversions(long long *arr, int n){
    return getInversionsByMergeSort(arr, 0, n-1);
}