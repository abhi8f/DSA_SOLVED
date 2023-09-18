vector<int> countFrequency(int n, int x, vector<int> &nums){
    vector<int> fq(n, 0);
    for(int x: nums) if (x<=n) fq[x-1]++;
    return fq;
}