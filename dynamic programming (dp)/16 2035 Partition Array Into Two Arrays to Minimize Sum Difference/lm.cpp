// TC: O(n*n/2*sum(positive))
// SC: O(n) + O(n*n/2*sum(positive))
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout<<#x<<": "<<x<<endl;
int h=1;
#define h() cout<<"h "<<h++<<endl;

int r(int i, int c, int k, vector<int> &arr, vector<vector<vector<int>>> &mv) {
    if (i<0) return c==0?abs(k):INT_MAX;
    if (mv[i][c][k]!=-1) return mv[i][c][k];
    return mv[i][c][k]= min(
        r(i-1,c,k,arr, mv),
        (c>=1 && k>=arr[i])?r(i-1,c-1,k-arr[i],arr, mv):INT_MAX
    );
}

class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n=arr.size();
        int mn=*min_element(arr.begin(),arr.end());
        if (mn<0){
            mn=abs(mn);
            for(int i=0;i<n;i++) arr[i]+=mn;
        }
        double k = 0;
        for (int i=0; i<n; i++) k += arr[i];
        if (k==0) return 0;
        k /= 2;
        int floatingCase = (int)k==k?0:1;
        int tar = (int)k;
        vector<vector<vector<int>>> mv(n,vector<vector<int>>(n/2+1,vector<int>(tar+1,-1)));
        return 2*r(n-1,n/2,tar,arr, mv)+floatingCase;
    }
};

int main(){
    Solution s;
    vector<int> v={-36,36};
    cout<<s.minimumDifference(v);
    return 0;
}