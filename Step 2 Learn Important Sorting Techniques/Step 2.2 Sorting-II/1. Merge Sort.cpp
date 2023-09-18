void mergeSort(vector<int> &arr, int l, int r) {
    if (l>=r) return;
    int mid= l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    
    int *temp= new int[r-l+1];
    int p=l, q=mid+1, k=0;
    while(p<=mid && q<=r){
        if (arr[p]<arr[q]) temp[k++]=arr[p++];
        else temp[k++]=arr[q++];
    }
    while(p<=mid) temp[k++]=arr[p++];
    while(q<=r) temp[k++]=arr[q++];
    
    for(k=l; k<=r; k++) arr[k]=temp[k-l];
    return;
}