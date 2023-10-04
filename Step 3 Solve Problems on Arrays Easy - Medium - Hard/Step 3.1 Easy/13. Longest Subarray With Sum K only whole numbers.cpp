int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n=a.size(), ans=0;
    unordered_map<long long, int> m;
    long long curSum=0;
    m[curSum] = -1;
    for(int i=0; i<n; i++){
        curSum+=a[i];
        if (m.find(curSum-k)!=m.end())
            ans=max(ans, i-m[curSum-k]);
        if (m.find(curSum)==m.end())
            m[curSum]=i;
    }
    return ans;
}


int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n=a.size(), ans=0;
    long long curSum=a[0];
    int i=0, j=0;
    while(j<n){
        if (curSum==k) {
            ans=max(ans, j-i+1);
            curSum+=((j+1)<n)?a[j+1]:0, j++;
        }
        else if (curSum>k) curSum-=a[i++];
        else curSum+=((j+1)<n)?a[j+1]:0, j++;
    }
    return ans;
}


