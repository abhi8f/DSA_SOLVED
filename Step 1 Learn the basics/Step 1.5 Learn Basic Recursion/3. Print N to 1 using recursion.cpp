void rec(int i, vector<int> &ans){
    if (i==0) return;
    ans.push_back(i);
    rec(i-1, ans);
}

vector<int> printNos(int x) {
    vector<int> ans;
    rec(x, ans);
    return ans;
}