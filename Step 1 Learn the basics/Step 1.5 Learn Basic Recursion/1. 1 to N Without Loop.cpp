void rec(int i, vector<int> &ans){
    if (i==0) return;
    rec(i-1, ans);
    ans.push_back(i);
}

vector<int> printNos(int x) {
    vector<int> ans;
    rec(x, ans);
    return ans;
}