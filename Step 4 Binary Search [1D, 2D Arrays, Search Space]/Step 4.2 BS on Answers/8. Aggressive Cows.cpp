#include<climits>

bool canPlace(vector<int> &stalls, int k, int  dist) {
    int preVal=stalls[0], n=stalls.size();
    k--;
    for(int i=1; i<n && k>0; i++) {
        if ((stalls[i] - preVal) >= dist){
            k--;
            preVal=stalls[i];
        }
    }
    return k==0;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int n= stalls.size();
    if (k>n) return -1;

    int low=1, high=stalls[n-1] - stalls[0], mid;
    
    while (low <= high) {
        mid = low + (high - low)/2;
        if (canPlace(stalls, k, mid)) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}