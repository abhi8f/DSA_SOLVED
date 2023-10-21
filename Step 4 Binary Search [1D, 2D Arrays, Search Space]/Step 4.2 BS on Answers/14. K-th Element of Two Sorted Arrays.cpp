#include<bits/stdc++.h>

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if (n>m) swap(n, m), swap(arr1, arr2);
    int low = max(0, k - m), high = min(k, n), mid1, mid2, l1, r1, l2, r2;

    while(low <= high){
        mid1 = low + (high - low) / 2;
        mid2 = k - mid1;
        l1 = (mid1>0) ? arr1[mid1 - 1] : INT_MIN;
        l2 = (mid2>0) ? arr2[mid2 - 1] : INT_MIN;
        r1 = (mid1<n) ? arr1[mid1] : INT_MAX;
        r2 = (mid2<m) ? arr2[mid2] : INT_MAX;
        
        if (r1 < l2) low = mid1 + 1; 
        else if (l1 > r2) high = mid1 - 1;
        else return max(l1, l2);
    }
    return 1;
}