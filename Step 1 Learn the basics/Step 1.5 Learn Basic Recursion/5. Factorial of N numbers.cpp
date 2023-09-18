vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    long long cur=1, mul=2;
    while(cur<=n) ans.push_back(cur), cur*=mul, mul++;
    return ans;
}

void rec(long long cur, long long mul, long long n, vector<long long> &ans){
    if (cur>n) return;
    ans.push_back(cur), cur*=mul, mul++;
    rec(cur, mul, n, ans);
}


vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    long long cur=1, mul=2;
    rec(cur, mul, n, ans);
    return ans;
}