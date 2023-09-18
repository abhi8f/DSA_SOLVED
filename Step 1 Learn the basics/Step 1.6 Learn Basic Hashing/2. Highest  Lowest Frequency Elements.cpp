vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> m;
    for(int x: v) m[x]++;
    int mn=INT_MAX, mnv=INT_MAX, mx=INT_MIN, mxv=INT_MAX;
    for(pair<int,int> p: m){
        if (p.second<mn) mn=p.second, mnv=p.first;
        else if (p.second==mn) mnv=min(mnv, p.first);
        if (p.second>mx) mx=p.second, mxv=p.first;
        else if (p.second==mx) mxv=min(mxv, p.first);
    }
    return {mxv, mnv};
}