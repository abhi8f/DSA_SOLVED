vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int mx=INT_MIN;
    for(int i=a.size()-1; i>=0; i--){
        if (a[i]>mx) ans.push_back(a[i]), mx=a[i];
    }
    return ans;
}