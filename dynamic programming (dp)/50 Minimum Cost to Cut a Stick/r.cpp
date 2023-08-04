// TC: O(n^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;

int r(int i, int j, vector<int>& cuts){
    if (j-i<2) return 0;
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(
            ans,
            cuts[j]-cuts[i] + r(i,k,cuts) + r(k,j,cuts)
        );
    }
    return ans;
}



class Solution {
   public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return r(0,cuts.size()-1,cuts);
    }
};

int main() {
    Solution s;
    // vector<int> ac = {1, 3, 4, 5};
    // cout << s.minCost(7, ac) << endl;
    // vector<int> ac={5,6,1,4,2};
    // cout<<s.minCost(9,ac)<<endl;
    vector<int> ac={1,3};
    cout<<s.minCost(5,ac)<<endl;
    return 0;
}