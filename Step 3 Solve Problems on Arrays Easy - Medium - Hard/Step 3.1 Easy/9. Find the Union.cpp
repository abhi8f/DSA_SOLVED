vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector<int> ans;

    int i=0, j=0, sa=a.size(), sb=b.size(), pre;

    while(i<sa && j<sb){
        pre=ans.empty()?-1:ans.back();

        if (a[i]==b[j]) {
            if (a[i]!=pre) ans.push_back(a[i]);
            i++, j++;
        }
        else if (a[i]<b[j]){
            if (a[i]!=pre) ans.push_back(a[i]);
            i++;
        } 
        else {
            if (b[j]!=pre) ans.push_back(b[j]);
            j++;
        }
    }

    while(i<sa) {
        if (ans.empty() || ans.back()!=a[i]) ans.push_back(a[i]);
        i++;
    }
    while(j<sb){
        if (ans.empty() || ans.back()!=b[j]) ans.push_back(b[j]);
        j++;
    }
    return ans;
}