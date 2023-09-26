vector<int> getSecondOrderElements(int n, vector<int> a) {
    int l, ll, s, ss;
    if (a[0]>a[1]) l=ss=a[0], ll=s=a[1];
    else l=ss=a[1], ll=s=a[0];
    
    for(int i=2; i<n; i++){
        if (a[i]>l) ll=l, l=a[i];
        else if (a[i]>ll) ll=a[i];

        if (a[i]<s) ss=s, s=a[i];
        else if (a[i]<ss) ss=a[i];
    }
    return {ll, ss};
}
